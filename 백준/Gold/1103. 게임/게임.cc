#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#define INF 987654321
#define lld long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, m;
int arr[50][50];
int visited[50][50];
int cache[50][50];
int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int ans;

bool checkRange(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < m;
}

void solve(int y, int x, int d, int visited[][50]) {
	if(visited[y][x] == 1 || ans == -1) {
		ans = -1;
		return;
	}
	if(cache[y][x] < d) {
		cache[y][x] = d;
	} else {
		return;
	}
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++) {
		int cy = y + r[i][0] * arr[y][x];
		int cx = x + r[i][1] * arr[y][x];
		if(checkRange(cy, cx) && arr[cy][cx] != -1) {
			solve(cy,cx, d+1, visited);
		} else {
			if(ans == -1) break;
			ans = max(ans, d+1);
		}
	}
	visited[y][x] = 0;
}

int main() {
	FAST_IO
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++) {
			if(s[j] == 'H') arr[i][j] = -1;
			else arr[i][j] = s[j]-'0';
		}
	}
	for(int i = 0; i<n;i++)for(int j=0;j<m;j++)cache[i][j]=-1;
	solve(0, 0, 0, visited);
	cout << ans << endl;
	return 0;
}