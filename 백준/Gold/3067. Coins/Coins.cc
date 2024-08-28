#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#define lld long long int
#define MAX_N 10000002

using namespace std;

int solve(const vector<int>& coins, int index, int target) {
	int dp[20][10001];
	for(int i = 0; i < coins.size(); i++) dp[i][0] = 1;
	for(int i = 1; i <= target; i++) {
		for(int j = 0; j < coins.size(); j++) {
			if(j == 0) {
				dp[0][i] = i % coins[0] == 0;
			} else if (i-coins[j] >= 0 && j > 0) {
				dp[j][i] = dp[j][i-coins[j]] + dp[j-1][i];
			} else {
				dp[j][i] = dp[j-1][i];
			}
		}
	}
	return dp[coins.size() - 1][target];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, k;
	cin >> n;
	for(int i = 0; i < n; i++) {
		vector<int> coins;
		cin >> k;
		for(int j = 0; j < k; j++) {
			int c;
			cin >> c;
			coins.push_back(c);
		}
		int target_bill = 0;
		cin >> target_bill;
		int answer = solve(coins, 0, target_bill);
		// cout << "INDEX " << i << ": " << answer << endl;
		cout << answer << endl;
	}
	return 0;
}

/**
 dp[i] == 현재 가지고 있는 동전으로 i원을 만들 수 있는 경우의 수
1, 3
10
1+1+1+1+1+1+1+1+1+1
1+1+1+1+1+1+1+3
1+1+1+1+3+3
1+3+3+3
= 4가지 경우의 수
dp[1] = 1
dp[2] = 1
dp[3] = dp[3-'1'] + 다음 


 */