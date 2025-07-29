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
#define PRN cout << "DEBUG" << endl

using namespace std;

int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N, M, empty_spaces, ANS = INF;
vector<vector<int>> lab;
vector<pair<int, int>> coords;

int solve(vector<int> v, vector<vector<bool>> visited) { // visited must initialized
	// cout << "SOLVE" << endl;
	int ans = 0;
	int filled = 0;
	priority_queue<pair<int, pair<int, int>>> pq;

	for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		int y = coords[*iter].first;
		int x = coords[*iter].second;
		pq.push({0, {y, x}});
		visited[y][x] = true;
		filled++;
	}

	while(!pq.empty()) {
		int d = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		// cout << ' ' << d << endl;
		if(lab[y][x] != 2) {
			ans = max(ans, d);
		}
		pq.pop();
		for(int i = 0; i < 4; i++) {
			int ny = y + r[i][0];
			int nx = x + r[i][1];
			if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
			filled++;
			pq.push({-d-1, {ny, nx}});
			visited[ny][nx] = true;
		}
	}
	// cout << filled << ' ' << empty_spaces << endl;
	// for(int i = 0; i < N; i++) {

	// 	for(int j = 0; j < N; j++) {
	// 		cout << lab[i][j];
	// 	}
	// 	cout << ' ';
	// 	for(int j = 0; j < N; j++) {
	// 		cout << visited[i][j];
	// 	}cout << endl;
	// }
	// cout << ans << endl;
	for(int i = 0; i < coords.size(); i++) {
		int y = coords[i].first;
		int x = coords[i].second;
		if(!visited[y][x]) {
			filled++;
		}
	}
	if(filled != empty_spaces) ans = INF;
	return ans;
}

void dfs(vector<int> v, int start_with, int depth, vector<vector<bool>> visited) { // start with like 0, 1, 2...
	for(int i = start_with; i < coords.size(); i++) {
		v.push_back(i);
		if(depth == M) {
			// TODO: call solve()
			ANS = min(ANS, solve(v, visited));
		} else {
			dfs(v, i+1, depth+1, visited);
		}
		v.pop_back();
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	vector<int> v;
	cin >> N >> M;
	lab = vector<vector<int>>(N, vector<int>(N));
	vector<vector<bool>> visited;
	visited = vector<vector<bool>>(N, vector<bool>(N));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> lab[i][j];
			if(lab[i][j] == 2) {
				coords.push_back({i, j});
			}
			if(lab[i][j] != 1) {
				empty_spaces++;
			}
			if(lab[i][j] == 1) {
				visited[i][j] = true;
			}
		}
	}
	dfs(v, 0, 1, visited);
	cout << (ANS == INF ? -1 : ANS) << endl;

	return 0;
}