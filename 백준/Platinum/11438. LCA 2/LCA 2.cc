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
백준 11438 LCA 2
이분탐색 LCA
*/
constexpr int MAX_K = 20;
int N, M;
vector<vector<int>> adj;
vector<int> depth;
vector<vector<int>> up;

inline int parent(const int node) {
    return up[node][0];
}

void init() {
    /* init */
    queue<pair<int, int>> q;
    q.push({1, 0}); // node, depth
    vector<bool> visited(N + 1);
    visited[1] = true;
    while(!q.empty()) {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();
        for(int i = 0; i < adj[node].size(); i++) {
            const int next = adj[node][i];
            if(!visited[next]) {
                visited[next] = true;
                // parent[next] = node;
                up[next][0] = node;
                depth[next] = d + 1;
                q.push({next, d + 1});
            }
        }
    }

    // up[x][k] := up[up[x][k-1]][k-1]
    for(int k = 1; k < MAX_K; k++) {
        for(int i = 1; i <= N; i++) {
            up[i][k] = up[up[i][k-1]][k-1];
        }
    }
}

int lca(int u, int v) {
    /* set depth as same */
    if(depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    int k = 0;
    while(diff > 0) {
        if(diff & 1) {
            u = up[u][k];
        }
        k++;
        diff = (diff >> 1);
    }
    if(u == v) return u;

    /* find */
    for(int k = MAX_K-1; k >= 0; k--) {
        if(up[u][k] != up[v][k]) {
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int a, b;
    adj = vector<vector<int>>(N + 1);
    depth = vector<int>(N+1);
    up = vector<vector<int>>(N + 1, vector<int>(MAX_K, 0));
    for(int i = 0; i < N-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    init();
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    
    return 0;
}
