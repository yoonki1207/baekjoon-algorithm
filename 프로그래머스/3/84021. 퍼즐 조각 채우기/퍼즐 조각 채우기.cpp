#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321

using namespace std;

int r[4][4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void printCoords(const vector<pair<int, int>>& coords) {
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++) {
			bool isFit = false;
			for(int k = 0; k < coords.size(); k++) {
				if(coords[k].first == i && coords[k].second == j) isFit = true;
			}
			cout << (isFit ? 1 : 0) << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void dfs(vector<vector<int>>& arr, int y, int x, vector<pair<int, int>>& coords, const int block_code) {
	arr[y][x] = -1;
	coords.push_back({y, x});
	for(int i = 0; i < 4; i++) {
		int ny = y + r[i][0];
		int nx = x + r[i][1];
		if(ny < 0 || nx < 0 || ny >= arr.size() || nx >= arr.size()) continue;
		if(arr[ny][nx] == block_code) {
			dfs(arr, ny, nx, coords, block_code);
		}
	}
}

void coordCompress(vector<pair<int, int>>& coords) { // set coords at corner
	int min_x = INF, min_y = INF;
	for(int i = 0; i < coords.size(); i++) {
		min_y = min(min_y, coords[i].first);
		min_x = min(min_x, coords[i].second);
	}
	for(int i = 0; i < coords.size(); i++) {
		coords[i].first -= min_y;
		coords[i].second -= min_x;
	}
}

void rotateCoord(vector<pair<int, int>>& coords) { // Rotate 90 unclockwise
	for(int i = 0; i < coords.size(); i++) {
		int y = coords[i].first;
		int x = coords[i].second;
		coords[i].first = -x;
		coords[i].second = y;
	}
	coordCompress(coords);
}

vector<pair<int, int>> getPolygon(vector<vector<int>>& arr, int y, int x, const int block_code) { // return polygons coords == polygon
	vector<pair<int, int>> coords;
	dfs(arr, y, x, coords, block_code);

	// coord compress
	coordCompress(coords);
	// sort coords
	sort(coords.begin(), coords.end());
	return coords;
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
	vector<vector<pair<bool, vector<pair<int, int>>>>> polygons(7);
	for(int i = 0; i < table.size(); i++) {
		for(int j = 0; j < table.size(); j++) {
			if(table[i][j] == 1) {
				vector<pair<int, int>> polygon = getPolygon(table, i, j, 1);
				int nPolygon = polygon.size();
				polygons[nPolygon].push_back({false, polygon});
			}
		}
	}
	// ^ get all table's polygon.
	// compare with gameboard
	vector<vector<bool>> visited;
	visited = vector<vector<bool>>(game_board.size(), vector<bool>(game_board.size()));
	for(int i = 0; i < game_board.size(); i++) {
		for(int j = 0; j < game_board.size(); j++) {
			if(game_board[i][j] == 0 && !visited[i][j]) { // TODO: visited 처리
				vector<pair<int, int>> spacedPolygon = getPolygon(game_board, i, j, 0);
				int nSpacedPolygon = spacedPolygon.size();
				sort(spacedPolygon.begin(), spacedPolygon.end());
				vector<pair<bool, vector<pair<int, int>>>>& tPolygons = polygons[nSpacedPolygon];
				bool isFit = false;
				for(int k = 0; k < tPolygons.size(); k++) { // 같은 길이에 대한 모든 polygon을 검사한다. 
					bool isVisited = tPolygons[k].first; // 이미 배치된 경우
					if(isVisited) continue; // 패스한다.
					vector<pair<int, int>> tCoords = tPolygons[k].second;
					for(int l = 0; l < 4; l++) { // 회전하면서 맞춰본다.
						sort(tCoords.begin(), tCoords.end());
						bool fit = true;
						for(int m = 0; m < tCoords.size(); m++) {
							int y = spacedPolygon[m].first;
							int x = spacedPolygon[m].second;
							int ty = tCoords[m].first;
							int tx = tCoords[m].second;
							if(y != ty || x != tx) {
								fit = false;
							}
						}
						if(fit) isFit = true;
						rotateCoord(tCoords);
					}
					if(isFit) {
						tPolygons[k].first = true;
						answer += nSpacedPolygon;
						break;
					}
				}
			}
		}
	}

    return answer;
}
