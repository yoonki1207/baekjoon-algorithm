#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int n, m;
int arr[1000][1000];
int dp[1000][1000][3];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
			for(int k = 0; k < 3; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	for(int j = 0; j < m; j++) for(int k = 0; k < 3; k++) dp[0][j][k] = arr[0][j];
	for(int j = 0; j < m; j++) {
		if(j > 0) {
			dp[1][j][0] = min(dp[0][j-1][1], dp[0][j-1][2]) + arr[1][j];	
		} 
		dp[1][j][1] = min(dp[0][j][0], dp[0][j][2]) + arr[1][j];
		if(j < m - 1) {
			dp[1][j][2] = min(dp[0][j+1][0], dp[0][j+1][1]) + arr[1][j];
		}
	}
	for(int i = 2; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(j > 0) {
				dp[i][j][0] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + arr[i][j];	
			} 
			dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + arr[i][j];
			if(j < m - 1) {
				dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j+1][1]) + arr[i][j];
			}
			
		}
	}
	int ans = INF;
	for(int i = 0; i < m; i++) {
		for(int k = 0; k < 3; k++) {
			ans = min(ans, dp[n-1][i][k]);
		}
	}
	cout << ans << endl;
	// dp[i][j][k] == 직전에 k방향을 산택했을 때 i, j위치에 온 경우의 최소 연료.
	// 000
	// 111
	// 222
	
	return 0;
}
