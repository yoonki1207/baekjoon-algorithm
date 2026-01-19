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
백준 2150
코사라주 알고리즘 SCC
*/
int V, E;
vector<vector<int>> adj;
vector<vector<int>> reverse_adj;

// 어짜피 정렬 후 연산이고 중복 안되니까 임의로
bool customSort(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

void dfs(int node, const vector<vector<int>>& mat, vector<bool>& visited, vector<int>& ret) {
    for(auto next: mat[node]) {
        if(visited[next]) continue;
        visited[next] = true;
        dfs(next, mat, visited, ret);
    }
    ret.push_back(node);
}

vector<vector<int>> kosaraju() {
    vector<bool> visited(V + 1, false);
    vector<int> stk;
    for(int i = 1; i <= V; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited, stk);
        }
    }

    visited = vector<bool>(V + 1, false);
    vector<vector<int>> ret;
    while(!stk.empty()) {
        int start_node = stk.back();
        stk.pop_back();
        if(visited[start_node]) continue;
        visited[start_node] = true;
        vector<int> s;
        dfs(start_node, reverse_adj, visited, s);
        
        ret.push_back(s);
    }
    for(int i = 0; i < ret.size(); i++) {
        sort(ret[i].begin(), ret[i].end());
    }
    sort(ret.begin(), ret.end(), customSort);
    return ret;
}


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    adj = vector<vector<int>>(V + 1);
    reverse_adj = vector<vector<int>>(V + 1);
    int from, to;
    for(int i = 0; i < E; i++) {
        cin >> from >> to;
        adj[from].push_back(to);
        reverse_adj[to].push_back(from);
    }

    for(int i = 1; i <= V; i++) {
        sort(adj[i].begin(), adj[i].end());
        sort(reverse_adj[i].begin(), reverse_adj[i].end());
    }
    vector<vector<int>> ans = kosaraju();
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << "-1\n";
    }
    return 0;
}
