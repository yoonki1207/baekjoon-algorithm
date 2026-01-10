#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#include <string.h>
#include <time.h>
#define INF 987654321
#define lld long long int
#define pii pair<int, int>
// #define DEBUG
// #define MOD 1000000009

using namespace std;

/*
백준 11812 K진 트리 19:45

mathmetics

둘 중 깊이가 더 깊은 노드의 조상 노드와 남은 노드를 비교하며 올라가기.

노드의 depth = sigma()
*/
int N, M;
int S_NODE, E_NODE;
vector<vector<pair<int, int>>> adj; // adjacency list
vector<int> PATH;

int dijkstra(const int start_node, const int end_node) {
    vector<int> dist(N + 1, INF);
    vector<int> path(N + 1);
    for(int i = 0; i < N + 1; i++) path[i] = i;
    dist[start_node] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start_node});
    while(!pq.empty()) {
        int node = pq.top().second;
        int d = -pq.top().first;
        pq.pop();
        if(d > dist[node]) continue;
        for(auto iter: adj[node]) {
            int next_node = iter.first;
            int weight = iter.second;
            if(d + weight < dist[next_node]) {
                dist[next_node] = d + weight;
                path[next_node] = node;
                pq.push({-(d + weight), next_node});
            }
        }
    }
    int n = end_node;
    while(path[n] != n) {
        PATH.push_back(n);
        n = path[n];
    }
    PATH.push_back(n);
    return dist[end_node];
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    adj = vector<vector<pair<int, int>>>(N + 1);
    int a, b, c;
    for(int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    cin >> S_NODE >> E_NODE;
    cout << dijkstra(S_NODE, E_NODE) << '\n';
    cout << PATH.size() << '\n';
    for(int i = 0; i < PATH.size(); i++) {
        cout << PATH[PATH.size() - i - 1] << ' ';
    }
    
    return 0;
}