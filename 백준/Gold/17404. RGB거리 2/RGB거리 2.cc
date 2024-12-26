#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int n;
int arr[1000][3];
int dp[1001][3];

int solve() {
	int ans = 987654321;
	for(int s = 0; s < 3; s++) {
		// cout << "S: " << s << ' ' << arr[0][s] << endl;
		dp[0][0] = dp[0][1] = dp[0][2] = INF;
		dp[0][s] = arr[0][s];
		for(int i = 1; i < n-1; i++) {
			// i-1 까지 칠했을 때 i를 어떻게 칠해야 최소비용일까?
			dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
		}
		
		// int x =  dp[n-1][s] = min(dp[n-2][(s+1)%3], dp[n-2][(s+2)%3]) + arr[n-1][s];
		for(int i = 0; i < 3; i++) {
			dp[n-1][i] = min(dp[n-2][(i+1)%3], dp[n-2][(i+2)%3]) + arr[n-1][i];
			if(i == s) dp[n-1][i] = INF;
		}

		// for(int i = 0; i < n; i++) {
		// 	for(int j = 0; j < 3; j++) {
		// 		cout << dp[i][j] << ' ';
		// 	} cout << endl;
		// }cout << endl;
		ans = min(ans, min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]));
	}
	return ans;
}

void Input() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	Input();
	int ans = solve();
	cout << ans;

	return 0;
}

/**
 

 3
26 40 83
49 60 57
13 89 99


26 89 
40 86
83 83

 */