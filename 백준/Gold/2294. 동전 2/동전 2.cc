#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int n, k; // 100, 10'000
vector<int> v;
vector<int> dp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	v = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	//int dp[10001] = { 0 };/*
	//memset(dp, INF, sizeof*/(dp));
	dp = vector<int>(k + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - v[j] >= 0) {
				dp[i] = min(dp[i], dp[i - v[j]] + 1);
			}
		}
	}
	cout << (dp[k] == INF ? -1 : dp[k]) << endl;
	return 0;
}