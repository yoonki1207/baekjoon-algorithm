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
백준 15681

*/
int N, R, Q;
vector<vector<int>> adj;
vector<pair<int, vector<int>>> tree;

int makeTree(const int currentNode, const int parent) {
    int cnt = 1;
    for(int i = 0; i < adj[currentNode].size(); i++) {
        int node = adj[currentNode][i];
        if(node != parent) {
            tree[currentNode].second.push_back(node);
            cnt += makeTree(node, currentNode);
        }
    }
    return tree[currentNode].first = cnt;
}


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> R >> Q;
    int u, v;
    adj = vector<vector<int>>(N + 1);
    tree = vector<pair<int, vector<int>>>(N + 1);
    for(int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    makeTree(R, -1);
    // queries
    int query;
    for(int i = 0; i < Q; i++) {
        cin >> query;
        cout << tree[query].first << '\n';
    }
    return 0;
}
