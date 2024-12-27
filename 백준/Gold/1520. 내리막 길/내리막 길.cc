#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[500][500];
int dp[500][500];
int offset[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int m, n;
int ans;

bool isOutOfIndex(int y, int x) {
	if(y < 0 || y >= m || x < 0 || x >= n) return true;
	return false;
}

void solve() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({arr[0][0], {0, 0}});
	dp[0][0] = 1;
	while(!pq.empty()) {
		pair<int, pair<int, int>> top = pq.top();
		pq.pop();
		const int currentPoint = arr[top.second.first][top.second.second];
		if(dp[top.second.first][top.second.second] && top.second.first != 0 && top.second.second != 0) continue;
		for(int i = 0; i < 4; i++) {
			int offsetY = top.second.first + offset[i][0];
			int offsetX = top.second.second + offset[i][1];
			if(isOutOfIndex(offsetY, offsetX)) continue;
			const int neighborPoint = arr[offsetY][offsetX];
			if(currentPoint < neighborPoint) {
				dp[top.second.first][top.second.second] += dp[offsetY][offsetX];
			} else if (currentPoint > neighborPoint) pq.push({arr[offsetY][offsetX], {offsetY, offsetX}});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> m >> n;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	// cout << endl;
	// for(int i = 0; i < m; i++, cout << endl) for(int j = 0; j < n; j++) cout << dp[i][j] << ' ';
	// cout << endl;
	cout << dp[m-1][n-1] << endl;
	return 0;
}
/**
4 5
50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10

1  1  1  1  1
1  0  0  0  1




 */