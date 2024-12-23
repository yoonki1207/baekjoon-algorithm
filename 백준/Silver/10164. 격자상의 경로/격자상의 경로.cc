#include <iostream>
#include <algorithm>

using namespace std;

int cache[31][31];

// int comb(int n, int r) {
// 	if(cache[n][r] || cache[n][n-r]) return cache[n][r];
// 	if(r == 1) return n;
// 	if(n == 1 || n == r) return 1;
// 	return cache[n][r] = cache[n][n-r] = comb(n - 1, r - 1) + comb(n - 1, r);
// }

int solve(int n, int m) {
	int dp[16][16] = {0};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i == 0 || j == 0) dp[i][j] = 1;
			else dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	return dp[n-1][m-1];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n, m, c; // 3 5 8
	cin >> n >> m >> c;
	c -= 1;
	int ans = 0;
	if(c<0) {
		ans = solve(n, m);
	} else {
		int y = c / m; // 1
		int x = c % m; // 2
		ans = solve(y+1, x+1) * solve(n-y, m-x);
		// cout << y+1 << ' ' << x+1 << ' '<< n-y << ' ' <<m-x << endl;
	}
	cout << ans;
	return 0;
}