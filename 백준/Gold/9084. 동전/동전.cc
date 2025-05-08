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
		v = vector<int>(n);
		ans = 0;
		for(int i = 0; i < n; i++) cin >> v[i];
		int target; cin >> target;
		dp = vector<vector<int>>(n, vector<int>(target+1, 0));
		for(int i = 0; i <= target; i+=v[0]) {
			dp[0][i] = 1;
		}
		for(int i = 1; i < n; i++) {
			for(int j = 0; j <= target; j++) {
				for(int l = 0; l <= j; l+=v[i]) {
					dp[i][j] += dp[i-1][j-l];
				}
			}
		}
		cout << dp[n-1][target] << '\n';
	}
	return 0;
}