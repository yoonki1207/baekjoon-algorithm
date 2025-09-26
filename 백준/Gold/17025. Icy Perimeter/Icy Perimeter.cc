#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#define INF 987654321
#define lld long long

using namespace std;

int N;
const int r[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
char arr[1001][1001];
bool visited[1001][1001];
string s;

bool checkRange(int y, int x) {
	return y >= 0 && x >= 0 && y < N && x < N;
}

int getLen(int y, int x) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + r[i][0];
		int nx = x + r[i][1];
		if (checkRange(ny, nx) == false || arr[ny][nx] == '.') {
			ret++;
		}
	}
	return ret;
}

void dfs(int y, int x, int& area, int& len) {
	if (visited[y][x]) return;
	area++;
	len += getLen(y, x);
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + r[i][0];
		int nx = x + r[i][1];
		if (checkRange(ny, nx) && arr[ny][nx] == '#') {
			dfs(ny, nx, area, len);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j];
		}
	}
	int max_a = 0, min_len = 987654321;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '#') {
				int area = 0, len = 0;
				dfs(i, j, area, len);
				if (max_a < area) {
					max_a = area;
					min_len = len;
				}
				else if (max_a == area) {
					min_len = min(min_len, len);
				}
			}
		}
	}
	cout << max_a << ' ' << min_len;
	return 0;
}