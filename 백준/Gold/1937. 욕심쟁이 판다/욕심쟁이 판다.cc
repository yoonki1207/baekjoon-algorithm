#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <string>
#define INF 987654321
#define lld long long
#define MAX_N 1000001

using namespace std;

int n;
vector<pair<int, pair<int, int>>> v;
vector<vector<int>> arr;
vector<vector<int>> dp;
const int r[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool checkRange(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < n;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v = vector<pair<int, pair<int, int>>>(n*n);
	arr = vector<vector<int>>(n, vector<int>(n, 0));
	dp = vector<vector<int>>(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int x = 0;
			cin >> x;
			v[i*n+j].first = x;
			v[i*n+j].second.first = i;
			v[i*n+j].second.second = j;
			arr[i][j] = x;
		}
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i = 0; i < v.size(); i++) {
		int value = v[i].first;
		int y = v[i].second.first;
		int x = v[i].second.second;
		for(int j = 0; j < 4; j++) {
			int ny = y + r[j][0];
			int nx = x + r[j][1];
			if(!checkRange(ny, nx)) continue;
			if(value > arr[ny][nx]) {
				dp[y][x] = max(dp[y][x], dp[ny][nx] + 1);
			}
		}
		ans = max(ans, dp[y][x]);
	}
	cout << ans +1 << '\n';

	return 0;
}