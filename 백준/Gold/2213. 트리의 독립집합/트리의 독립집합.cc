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
#define pdd pair<double, double>
// #define DEBUG
// #define MOD 1000000009

using namespace std;

/*
백준 2213 트리의 독립집합

*/
constexpr int MAX_N = 10001;
int N;
vector<int> cost;
vector<vector<int>> adj;
int dp[MAX_N][2];

void dfs(int node, vector<bool>& visited) {
    dp[node][0] = 0;
    dp[node][1] = cost[node];
    visited[node] = true;
    for(int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if(visited[next]) continue;
        dfs(next, visited);
        dp[node][0] += max(dp[next][0], dp[next][1]);
        dp[node][1] += dp[next][0];
    }
}

void tracing(int node, int prev, vector<bool>& visited, vector<int>& path) {
    if(dp[node][1] > dp[node][0] && !visited[prev]) {
        path.push_back(node);
        visited[node] = true;
    }
    for(int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if(prev == next) continue;
        tracing(next, node, visited, path);
    }
}

void solve() {
    vector<bool> visited(N + 1, false);
    dfs(1, visited);
    fill(visited.begin(), visited.end(), false);
    vector<int> path;
    tracing(1, 0, visited, path);
    sort(path.begin(), path.end());
    cout << max(dp[1][0], dp[1][1]) << '\n';
    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << ' ';
    }
}


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    adj = vector<vector<int>>(N + 1);
    cost = vector<int>(N + 1);
    for(int i = 1; i <= N; i++) cin >> cost[i];
    int a, b;
    for(int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve();
    return 0;
}
