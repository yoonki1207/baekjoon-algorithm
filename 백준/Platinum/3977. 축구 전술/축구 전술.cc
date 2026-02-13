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
백준 3977
SCC

*/
int T, N, M, A, B;
vector<vector<int>> adj;
vector<vector<int>> rev;

vector<vector<int>> getSCC() {
    vector<int> v;
    vector<bool> visited(N);
    vector<int> tmp;
    for(int start_node = 0; start_node < N; ++start_node) {
        if(visited[start_node]) continue;
        visited[start_node] = true;
        tmp.push_back(start_node);
        while(!tmp.empty()) {
            int top_node = tmp.back();
            bool isVisitable = false;
            for(int i = 0; i < adj[top_node].size(); i++) {
                int next_node = adj[top_node][i];
                if(!visited[next_node]) {
                    visited[next_node] = true;
                    tmp.push_back(next_node);
                    isVisitable = true;
                    break;
                }
            }
            if(!isVisitable) {
                v.push_back(tmp.back());
                tmp.pop_back();
            }
        }
    }
    tmp.clear();
    visited = vector<bool>(N);
    vector<vector<int>> ret;
    while(v.size() > 0) {
        int node = v.back();
        v.pop_back();
        if(visited[node]) continue;
        visited[node] = true;
        vector<int> scc;
        scc.push_back(node);
        tmp.clear();
        tmp.push_back(node);
        while(tmp.size()) {
            node = tmp.back();
            bool isDone = true;
            for(int i = 0; i < rev[node].size(); i++) {
                int next = rev[node][i];
                if(!visited[next]) {
                    visited[next] = true;
                    scc.push_back(next);
                    tmp.push_back(next);
                    isDone = false;
                    break;
                }
            }
            if(isDone) {
                tmp.pop_back();
            }
        }
        ret.push_back(scc);
    }
    return ret;
}

vector<int> solve() {
    // SCC의 연결 요소를 찾아 만약 indegree == 0 인 SCC가 유일하다면, 해당 집합의 모든 원소가 정답이다.
    vector<vector<int>> scc = getSCC();
    vector<int> indegree(scc.size(), 0);
    vector<int> parent(N, 0);
    for(int i = 0; i < scc.size(); i++) {
        for(int j = 0; j < scc[i].size(); j++) {
            int node = scc[i][j];
            parent[node] = i;
        }
    }
    for(int i = 0; i < adj.size(); i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            int u = i; int v = adj[i][j];
            // u -> v
            if(parent[u] != parent[v]) {
                ++indegree[parent[v]];
            }
        }
    }
    int index = -1;
    vector<int> ret;
    for(int i = 0; i < indegree.size(); i++) {
        if(indegree[i] == 0) {
            if(index < 0) {
                index = indegree[i];
            } else {
                return ret;
            }
        }
    }
    if(index < 0) return ret;
    ret = scc[index];
    return ret;
}


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> M;
        adj = vector<vector<int>>(N);
        rev = vector<vector<int>>(N);
        for(int i = 0; i < M; i++) {
            cin >> A >> B;
            adj[A].push_back(B);
            rev[B].push_back(A);
        }
        vector<int> ans = solve();
        if(ans.size() == 0) {
            cout << "Confused\n";
        } else {
            sort(ans.begin(), ans.end());
            for(int i = 0; i < ans.size(); i++) {
                cout << ans[i] << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}
