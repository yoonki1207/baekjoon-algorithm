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

using namespace std;

// 백준 3197

const int r[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int R, C;
int arr[MAX_N][MAX_N]; // 1500^2 = 255만

inline bool checkRangeArr(int y, int x) { return y >= 1 && x >= 1 && y <= R && x <= C; }

inline bool checkRange(int y, int x) { 
	return checkRangeArr(y, x);
	//return y >= 0 && x >= 0 && y < R+2 && x < C+2; 
}

queue<pair<int, int>> bfs(queue<pair<int, int>> q, int val) {
	queue<pair<int, int>> retq;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + r[i][0];
			int nx = x + r[i][1];
			if (arr[ny][nx] == INF) {
				arr[ny][nx] = val;
				retq.push({ ny, nx });
			}
		}
	}
	return retq;
}

void initMatrix() {
	queue<pair<int, int>> q, next_q;
	vector<vector<bool>> visited(R+2, vector<bool>(C+2));
	//q.push({ 0, 0 });
	//visited[0][0] = true;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] == 0) {
				q.push({ i, j });
				visited[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		//cout << y << ' ' << x << endl;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + r[i][0];
			int nx = x + r[i][1];
			if (checkRange(ny, nx) == false || visited[ny][nx]) continue;
			visited[ny][nx] = true;
			if (arr[ny][nx] == 0) {
				q.push({ ny, nx });
			} else if (arr[ny][nx] == INF) {
				next_q.push({ ny, nx });
				arr[ny][nx] = 1;
			}
		}
	}
	int val = 2;
	while (true) {
		next_q = bfs(next_q, val);
		++val;
		if (next_q.size() == 0) break;
	}
	return;
}

void printMatrix() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << (arr[i][j] == INF ? 'X': (char)(arr[i][j] + '0'));
		}
		cout << endl;
	}
	cout << endl;
}

int solve(vector<pair<int, int>> coords) {
	int start_y = coords[0].first;
	int start_x = coords[0].second;
	int end_y = coords[1].first;
	int end_x = coords[1].second;
	priority_queue<
		pair<int, pair<int, int>>, 
		vector<pair<int, pair<int, int>>>, 
		greater<pair<int, pair<int, int>>>
		> pq;
	vector<vector<bool>> visited(R + 2, vector<bool>(C + 2));
	pq.push({ 0, {start_y, start_x} });
	visited[start_y][start_x] = true;
	while (!pq.empty()) {
		int val = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		if (y == end_y && x == end_x) {
			return val;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + r[i][0];
			int nx = x + r[i][1];
			if (checkRangeArr(ny, nx) == false || visited[ny][nx]) continue;
			visited[ny][nx] = true;
			pq.push({ max(val, arr[ny][nx]), {ny, nx} });
		}
	}
	return -1;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	vector<pair<int, int>> swan_coords;
	for (int i = 1; i <= R; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= C; j++) {
			char c = s[j-1];
			if (c == 'X') {
				arr[i][j] = INF;
			}
			else if (c == 'L') {
				swan_coords.push_back({ i, j });
			}
			else {
				arr[i][j] = 0;
			}
		}
	}
	initMatrix();
	int answer = solve(swan_coords);
	cout << answer << endl;
	return 0;
}

/*
어떤 빙판이 몇일 이후에 사라지는지 알려면, 
해당 빙판 주위의 네 방향 중 가장 작은 값을 가지는 빙판 + 1을 해주면 된다.
만약 주위에 0,x,x,x 이면, 0+1을 하면 된다.
만약 주위에 1,x,x,x 이면, 1+1을 하면 된다. (x는 최소 1이기 때문)
그냥 queue에 bfs하면 될듯
*/