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

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

// 백준 2931

const int r[4][2] = { {-1, 0},{1, 0}, {0, -1}, {0, 1} }; // U, D, L, R
const string dir_nodes[4] = {
	"|+14",
	"|+23",
	"-+12",
	"-+34"
};
int R, C;
char arr[25][25];
pair<int, int> moscow;
pair<int, int> zagreb;

bool checkRange(int y, int x) { return y >= 0 && x >= 0 && y < R && x < C; }
bool isin(const char node, string nodes) {
	for (int i = 0; i < nodes.size(); i++) if (node == nodes[i]) return true;
	return false;
}
char sample(int y, int x) {
	bool rs[4] = { 0 };
	for (int i = 0; i < 4; i++) {
		int ny = y + r[i][0];
		int nx = x + r[i][1];
		if (!checkRange(ny, nx)) continue;
		if (isin(arr[ny][nx], dir_nodes[i])) rs[i] = true;
	}
	if (rs[0] && rs[1] && rs[2] && rs[3]) return '+';
	if (rs[0] && rs[1]) return '|';
	if (rs[2] && rs[3]) return '-';
	if (rs[DOWN] && rs[RIGHT]) return '1';
	if (rs[RIGHT] && rs[UP]) return '2';
	if (rs[UP] && rs[LEFT]) return '3';
	return '4';
}
int next_node_dir(int y, int x, int dir) {
	char node = arr[y][x];
	if (dir == UP) {
		if (node == '|' || node == '+')	return UP;
		else if (node == '1') return RIGHT;
		else if (node == '4') return LEFT;
	}
	else if (dir == DOWN) {
		if (node == '|' || node == '+') return DOWN;
		else if (node == '2') return RIGHT;
		else if (node == '3') return LEFT;
	}
	else if (dir == LEFT) {
		if (node == '-' || node == '+') return LEFT;
		else if (node == '1') return DOWN;
		else if (node == '2') return UP;
	}
	else {
		if (node == '-' || node == '+') return RIGHT;
		else if (node == '3') return UP;
		else if (node == '4') return DOWN;
	}
	return -1;
}
void solve() {
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < 4; i++) {
		int ny = moscow.first + r[i][0];
		int nx = moscow.second + r[i][1];
		if (!checkRange(ny, nx)) continue;
		char node = arr[ny][nx];
		if (isin(node, dir_nodes[i])) {
			q.push({ i, {ny, nx} });
			// break; // 통로는 유일하니 없어도 됨
		}
	}
	while (!q.empty()) {
		int d = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		//cout << y << ' ' << x << endl;
		q.pop();
		int nd = next_node_dir(y, x, d);
		int ny = y + r[nd][0];
		int nx = x + r[nd][1];
		if (ny == zagreb.first && nx == zagreb.second) {
			break;
		}
		if (arr[ny][nx] == '.') {
			char empty_node = sample(ny, nx);
			cout << ny+1 << ' ' << nx+1 << ' ' << empty_node;
			break;
		}
		else {
			q.push({ nd, {ny, nx} });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	string s;
	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < C; j++) {
			arr[i][j] = s[j];
			if (s[j] == 'M') moscow = { i, j };
			if (s[j] == 'Z') zagreb = { i, j };
		}
	}
	solve();

	return 0;
}
