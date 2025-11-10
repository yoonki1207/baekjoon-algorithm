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
#define pii pair<int, int>

using namespace std;

int N, M;
int adj[101][101];
int arr[101][101];

vector<int> dijkstra(int start_node) {
	vector<int> dist(N+1, INF);
	priority_queue<pii,
		vector<pii>, 
		greater<pii>> pq;
	pq.push({ 0, start_node });
	dist[start_node] = 0;
	while (!pq.empty()) {
		int curr_dist = pq.top().first; // start to n (curr)
		int curr = pq.top().second;
		pq.pop();
		if (curr_dist > dist[curr]) continue;
		for (int next = 1; next <= N; next++) {
			if (next != curr && adj[curr][next] != INF) {
				if (curr_dist + adj[curr][next] < dist[next]) {
					dist[next] = curr_dist + adj[curr][next];
					pq.push({ dist[next], next });
				}
			}
		}
	}
	return dist;
}

void solve() {
	for (int i = 1; i <= N; i++) {
		vector<int> v = dijkstra(i);
		for (int j = 1; j <= N; j++) {
			arr[i][j] = v[j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			adj[i][j] = INF;
		}
	}
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}

	solve();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << (arr[i][j] == INF ? 0 : arr[i][j]) << ' ';
		}
		cout << '\n';
	}

	return 0;
}
