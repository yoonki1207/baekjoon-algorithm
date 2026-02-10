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
백준 4196


*/
int N, M, T;
int x, y;
vector<vector<int>> forward_adj;
vector<vector<int>> backward_adj;
vector<int> comp;

vector<vector<int>> kosaraju() {
    vector<int> v, tmp;
    vector<bool> visited(N+1);
    for(int i = 1; i <= N; i++) {
        int node = i;
        if(visited[node]) continue;
        tmp.push_back(node);
        visited[node] = true;
        while(tmp.size()) {
            bool isVisited = false;
            node = tmp.back();
            for(int i = 0; i < forward_adj[node].size(); i++) {
                int next_node = forward_adj[node][i];
                if(!visited[next_node]) {
                    visited[next_node] = true;
                    tmp.push_back(next_node);
                    isVisited = true;
                    break;
                }
            }
            if(!isVisited) {
                v.push_back(tmp.back());
                tmp.pop_back();
            }
        }
    }
    visited = vector<bool>(N + 1, false);
    vector<vector<int>> ret;
    while(!v.empty()) {
        int node = v.back();
        v.pop_back();
        if(visited[node]) continue;
        visited[node] = true;
        // dfs
        vector<int> scc;
        scc.push_back(node);
        tmp.clear();
        tmp.push_back(node);
        while(tmp.size()) {
            // cout << node << endl;
            bool isVisited = false;
            node = tmp.back();
            for(int i = 0; i < backward_adj[node].size(); i++) {
                int next_node = backward_adj[node][i];
                if(!visited[next_node]) {
                    visited[next_node] = true;
                    isVisited = true;
                    scc.push_back(next_node);
                    tmp.push_back(next_node);
                    break;
                }
            }
            if(!isVisited) {
                tmp.pop_back();
            }
        }
        ret.push_back(scc);
    }
    return ret;
}

int cntIndegree(const vector<vector<int>>& scc) {
    vector<int> indegree(scc.size(), 0);
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < forward_adj[i].size(); j++) {
            int u = i;
            int v = forward_adj[i][j];
            if(comp[u] != comp[v]) {
                indegree[comp[v]]++;
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < indegree.size(); i++) {
        int cnt = indegree[i];
        if(cnt == 0) {
            ret++;
        }
    }
    return ret;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> M;
        forward_adj = vector<vector<int>>(N + 1);
        backward_adj = vector<vector<int>>(N + 1);
        comp = vector<int>(N + 1, 0);
        for(int i = 0; i < M; i++) {
            cin >> x >> y;
            forward_adj[x].push_back(y);
            backward_adj[y].push_back(x);
        }
        
        auto scc = kosaraju();

        for(int i = 0; i < scc.size(); i++) {
            for(int j = 0; j < scc[i].size(); j++) {
                int node = scc[i][j];
                comp[node] = i;
            }
        }
        
        int cnt = cntIndegree(scc);
        
        cout << cnt << '\n';
    }
    return 0;
}