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

int N, M, S, D, U, V, P;
vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, int>>> radj;
vector<vector<bool>> removed;

vector<int> dist;


void removeEdge() {
	queue<int> q;
	vector<bool> visited(N);
	q.push(D);
	while(!q.empty()) {
		int curr_node = q.front();
		q.pop();
		for(vector<pair<int, int>>::iterator iter = radj[curr_node].begin(); iter != radj[curr_node].end(); iter++) {
			int next_node = iter->first;
			int weight = iter->second; // curr_node -> next_node (reversed)
			if(dist[next_node] + weight == dist[curr_node]) {
				removed[next_node][curr_node] = true;
				if(!visited[next_node]) {
					visited[next_node] = true;
					q.push(next_node);
				}
			}
		}
	}
}

void dijkstra() {
	dist = vector<int>(N, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, S});
	dist[S] = 0;
	while(!pq.empty()) {
		// start_node부터 curr_node 까지의 현재 길이
		int curr_distance = pq.top().first;
		int curr_node = pq.top().second;
		pq.pop();
		if(curr_distance > dist[curr_node]) continue;
		vector<pair<int, int>>& edges = adj[curr_node];
		for(vector<pair<int, int>>::iterator iter = edges.begin(); iter != edges.end(); ++iter) {
			if(removed[curr_node][iter->first])continue;
			int new_distance = curr_distance + iter->second;
			if(new_distance < dist[iter->first]) {
				dist[iter->first] = new_distance;
				pq.push({dist[iter->first], iter->first});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while(true) {
		cin >> N >> M;
		if(N == 0 && M == 0) break;

		adj = vector<vector<pair<int, int>>>(N);
		radj = vector<vector<pair<int, int>>>(N);
		removed = vector<vector<bool>>(N, vector<bool>(N));

		cin >> S >> D;
		for(int i = 0; i < M; i++) {
			cin >> U >> V >> P;
			adj[U].push_back({V, P});
			radj[V].push_back({U, P});
		}
		dijkstra();
		removeEdge();
		dijkstra();
		cout << (dist[D] == INF ? -1 : dist[D]) <<  '\n';
	}
	
	return 0;
}