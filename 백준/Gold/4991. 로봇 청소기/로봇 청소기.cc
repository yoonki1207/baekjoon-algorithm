#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#define INF 987654321
#define MAX_N 1503
#define lld long long
#define pii pair<int, int>

using namespace std;

// 백준 

const int r[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int H, W;
char room[21][21];
vector<pair<int, int>> coords;
int matrix[11][11];
int ans;

bool checkRange(int y, int x) { return y >= 0 && x >= 0 && y < H && x < W; }

int getDistance(int sy, int sx, int ey, int ex) {
	queue<pair<int, pair<int, int>>> q;
	vector<vector<bool>> visited(H, vector<bool>(W));
	q.push({ 0, {sy, sx} });
	visited[sy][sx] = true;
	while (!q.empty()) {
		int moved = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + r[i][0];
			int nx = x + r[i][1];
			if (checkRange(ny, nx) == false || visited[ny][nx]) continue;
			if (room[ny][nx] == 'x') continue;
			visited[ny][nx] = true;
			if (ny == ey && nx == ex) {
				return moved + 1;
			}
			q.push({ moved + 1, {ny, nx} });
		}
	}
	return -1;
}

bool initMatrix() {
	// 10개에서 두 개를 꺼내는 경우의 수 = 10 C 2 = 45
	for (int i = 0; i < coords.size(); i++) {
		for (int j = i + 1; j < coords.size(); j++) {
			int distance = getDistance(coords[i].first, coords[i].second, coords[j].first, coords[j].second);
			if (distance < 0) return false;
			matrix[i][j] = matrix[j][i] = distance;
		}
	}
	return true;
}

void solve(int index, vector<bool> visited, int cost, int d) {
	if (d == coords.size()-1) {
		ans = min(ans, cost);
	}
	for (int i = 1; i < coords.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;
		solve(i, visited, cost + matrix[index][i], d+1);
		visited[i] = false;
	}
}

void solve() {
	vector<int> v(coords.size() - 1);
	for (int i = 1; i < coords.size(); i++) v[i-1] = i;
	do {
		int cost = matrix[0][v[0]];
		for (int i = 0; i < v.size()-1; i++) {
			cost += matrix[v[i]][v[i + 1]];
		}
		ans = min(ans, cost);
	} while (next_permutation(v.begin(), v.end()));
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true) {
		cin >> W >> H;
		if (W == 0 && H == 0) break;
		string s;
		coords.clear();
		vector<pair<int, int>> tmp;

		for (int i = 0; i < H; i++) {
			cin >> s;
			for (int j = 0; j < W; j++) {
				room[i][j] = s[j];
				if (room[i][j] == 'o') {
					coords.push_back({ i, j });
				}
				else if (room[i][j] == '*') {
					tmp.push_back({ i, j });
				}
			}
		}
		for (int i = 0; i < tmp.size(); i++) {
			coords.push_back(tmp[i]);
		}
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				matrix[i][j] = INF;
			}
		}
		ans = INF;
		bool solveable = initMatrix();

		if (solveable) {
			vector<bool> visited(coords.size());
			//solve(0, visited, 0, 0);
			solve();
		}


		cout << (ans == INF ? -1 : ans) << '\n';
	}
	

	/*
	탐색 문제임. 이미 "탐색한 상태"는 다시 방문할 필요 없음.
	이걸 줄이기 위해선 위치 뿐 아니라 청소를 얼마나 했는지도 중요함.
	왜냐면 같은 위치를 다시 방문해도 되기 때문임.
	*/

	/*
	그래프 문제 아님? dijkstra 하면 되는거 아닌가
	모든 정점을 방문하되 최소길이가 되게하는 것.
	이건 외판원문제?
	방문할 수 있는 청소지점은 최대 10개이다.
	n개라 했을 때 경우의 수는 n!
	10! = 약 362만
	걍 모든 경우의 수 다 돌아도 ㄱㅊ음
	*/
	
	


	return 0;
}