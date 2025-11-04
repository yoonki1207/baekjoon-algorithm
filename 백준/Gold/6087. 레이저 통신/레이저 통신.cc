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

// 백준 6087

const int r[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // UP, DOWN, LEFT, RIGHT
int W, H;
int ans = INF;
int arr[101][101];
vector<pair<int, int>> coords;

inline bool checkRange(int y, int x) { return y >= 0 && x >= 0 && y < H && x < W; }

bool orthogonal(int a, int b) {
	if (a == -1) return false;
	return a / 2 != b / 2;
}

void dfs(int y, int x, int prev_direction, int mirror_used, vector<vector<vector<int>>>& visited) {
	if (coords[1].first == y && coords[1].second == x) {
		ans = min(ans, mirror_used);
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + r[i][0];
		int nx = x + r[i][1];
		if (checkRange(ny, nx) == false || arr[ny][nx] == 1) continue;
		if (orthogonal(prev_direction, i)) { // 직각일때만
			if (visited[ny][nx][i] > mirror_used + 1) {
				visited[ny][nx][i] = mirror_used + 1;
				dfs(ny, nx, i, mirror_used + 1, visited);
			}
		}
		else if (prev_direction == i) { // 직진
			if (visited[ny][nx][i] > mirror_used) {
				visited[ny][nx][i] = mirror_used;
				dfs(ny, nx, i, mirror_used, visited);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> W >> H;
	string s;
	for (int i = 0; i < H; i++) {
		cin >> s;
		for (int j = 0; j < W; j++) {
			if (s[j] == '*') {
				arr[i][j] = 1;
			}
			else if(s[j] == 'C') {
				coords.push_back({ i, j });
			}
		}
	}
	// solve
	vector<vector<vector<int>>> visited(H, vector<vector<int>>(W, vector<int>(4, INF)));
	for (int i = 0; i < 4; i++) {
		dfs(coords[0].first, coords[0].second, i, 0, visited);
	}
	cout << ans;

	return 0;
}

/*

7 8
.......
......C
......*
*****.*
....*..
....**.
.C..*..
.......

*/