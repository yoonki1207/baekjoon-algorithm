#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int n;
lld dp[10][3];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> n;
	dp[1][0] = 2;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[2][0] = 7;
	dp[2][1] = 1;
	dp[2][2] = 1;
	int i = 0;
	int k = 4;
	for(int index = 3; index <= n; index++) {
		i = (index) % k;
		int a = (k-1+i) % k;
		int b = (k-2+i) % k;
        dp[i][0] = (dp[b][0]*3 + dp[a][0]*2 + dp[a][1] + dp[a][2]) % 1000000007;
        dp[i][1] = dp[i][2] = (dp[b][0] + dp[a][1]) % 1000000007;
	}
	cout << dp[n%k][0] << endl;
	return 0;
}