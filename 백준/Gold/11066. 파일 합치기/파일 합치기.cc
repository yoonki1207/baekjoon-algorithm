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

int T, n;
vector<int> v;
vector<vector<int>> dp;
int ans;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T-->0) {
		cin >> n;
		v = vector<int>(n+1);
		dp = vector<vector<int>>(n+1, vector<int>(n+1));
		ans = 0;
		for(int i = 1; i <= n; i++) {
			int x; cin >> x;
			v[i] = v[i-1] + x;
		}
		for(int k = 1; k < n; k++) {
			int i = 1;
			int j = k + 1;
			for(int u = 0; u < n-k; u++) {
				// cout << i << ' ' << j << endl;
				dp[i][j] = INF;
				for(int m = j - k; m <= j - 1; m++) {
					dp[i][j] = min(dp[i][j], dp[i][m] + dp[m+1][j] + v[j] - v[i-1]);
				}
				i++;
				j++;
			}
		}
		cout << dp[1][n] << '\n';
	}
	return 0;
}