#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321
#define lld long long
#define ull unsigned long long
#define MAX_N 500000

using namespace std;

int N, M, K;

vector<vector<pair<int, int>>> v;
vector<vector<lld>> dist;

lld solve() {
	dist = vector<vector<lld>>(K+1, vector<lld>(N+1, LONG_MAX));
	dist[0][1] = 0;
	priority_queue<pair<lld, pair<int, int>>> pq;
	for(int k = 0; k <= K; k++) {
		dist[k][1] = 0;
	}
	pq.push({0, {1, 0}});
	while(!pq.empty()) {
		lld d = -pq.top().first;
		int n = pq.top().second.first;
		int k = pq.top().second.second;

		pq.pop();

		if(dist[k][n] < d) continue;

		for(vector<pair<int, int>>::iterator iter = v[n].begin(); iter != v[n].end(); iter++) {
			int next_n = iter->first;
			lld next_d = iter->second;
			if(next_d + d < dist[k][next_n]) {
				dist[k][next_n] = next_d + d;
				pq.push({-dist[k][next_n], {next_n, k}});
			}
			if(k + 1 <= K && d < dist[k+1][next_n]) {
				dist[k+1][next_n] = d;
				pq.push({-dist[k+1][next_n], {next_n, k+1}});
			}
		}
	}
	lld min_cost = dist[K][N];
	for(int i = 1; i <= K; i++) {
		min_cost = min(min_cost, dist[i][N]);
	}
	return min_cost;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	v = vector<vector<pair<int, int>>>(N+1);
	for(int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	lld ans = solve();
	cout << ans << endl;
	return 0;
}
