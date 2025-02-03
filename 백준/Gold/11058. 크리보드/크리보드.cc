#include <iostream>
#include <algorithm>
#define lld long long

using namespace std;

lld solve(int n) {
	lld dp[101][3][2] = { 0 };
	for (int i = 1; i <= 4; i++) for (int j = 0; j < 3; j++) dp[i][j][0] = i;
	for (int i = 5; i <= n; i++) {
		dp[i][0][0] = dp[i - 1][0][0] + 1;
		dp[i][1][0] = max(2 * dp[i - 3][1][0], 2 * dp[i - 3][2][0]);
		if (2 * dp[i - 3][1][0] < 2 * dp[i - 3][2][0]) {
			dp[i][1][1] = dp[i - 3][2][0];
		}
		else if (2 * dp[i - 3][1][0] == 2 * dp[i - 3][2][0]) {
			dp[i][1][1] = max(dp[i - 3][2][0], dp[i - 3][1][0]);
		}
		else{
			dp[i][1][1] = dp[i - 3][1][0];
		}

		dp[i][2][0] = max(dp[i - 1][2][0] + dp[i - 1][2][1], dp[i - 1][1][0] + dp[i - 1][1][1]);
		if (dp[i - 1][2][0] + dp[i - 1][2][1] < dp[i - 1][1][0] + dp[i - 1][1][1]) {
			dp[i][2][1] = dp[i - 1][1][1];
		}
		else if (dp[i - 1][2][0] + dp[i - 1][2][1] == dp[i - 1][1][0] + dp[i - 1][1][1]) {
			dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][1]);
		} 
		else {
			dp[i][2][1] = dp[i - 1][2][1];
		}
	}
	return max(dp[n][0][0], max(dp[n][1][0], dp[n][2][0]));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	cout <<solve(n) << endl;
	return 0;
}
