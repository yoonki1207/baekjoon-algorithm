#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#define INF 987654321
#define MAX_N 1503
#define lld long long

using namespace std;

// 백준 17225

int N, M, K;
int dp[301][301];
vector<vector<pair<int, int>>> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	v = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b)continue; // 역항로 배제
		v[b].push_back({a, c});
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = -INF;
		}
	} dp[1][1] = 0;
	for (int i = 2; i <= M; i++) {	
		for (int j = 1; j <= N; j++) {
			vector<pair<int, int>>& prev = v[j]; // j번 도시로 가는 모든 항로
			// j == destination
			for (int k = 0; k < prev.size(); k++) {
				int depature = prev[k].first;
				int score = prev[k].second;
				dp[j][i] = max(dp[j][i], dp[depature][i-1] + score);
			}
		}
	}
	int ans = 0;
	for (int i = 2; i <= M; i++) {
		ans = max(ans, dp[N][i]);
	}
	cout << ans;
	return 0;
}

/*
3 3 5
1 3 7
1 2 5
2 3 3
1 3 4
3 1 100
> 8
3 2 5
1 3 7
1 2 5
2 3 3
1 3 4
3 1 100
> 7

3 3 4
1 3 1
2 3 10
1 3 4
3 1 100
> 4
*/