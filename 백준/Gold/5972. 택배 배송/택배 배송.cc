#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#include <set>
#define INF 987654321
#define lld long long
#define pii pair<int, int>

using namespace std;
/*
백준
*/
int N, M;
vector<vector<pair<int, int>>> adj;
map<pair<int, int>, int> m;

int dijkstra() {
    const int start_node = 1;
    vector<int> dist;
    dist = vector<int>(N + 1, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start_node });
    dist[start_node] = 0;
    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();
        if (dist[curr_node] < curr_dist) continue;
        for (auto iter = adj[curr_node].begin(); iter != adj[curr_node].end(); iter++) {
            int next_node = iter->first;
            int next_dist = iter->second;
            if (curr_dist + next_dist < dist[next_node]) {
                dist[next_node] = curr_dist + next_dist;
                pq.push({ dist[next_node], next_node });
            }
        }
    }
    return dist[N];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    adj = vector<vector<pair<int, int>>>(N + 1);
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        auto iter = m.find({ a, b });
        if (iter == m.end()) {
            m.insert({ {a, b}, c });
        }
        else {
            int d = iter->second;
            if (d > c) {
                m.at(iter->first) = c;
            }
        }
    }
    for (map<pair<int, int>, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        a = iter->first.first;
        b = iter->first.second;
        c = iter->second;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }
    cout << dijkstra();
    return 0;
}
