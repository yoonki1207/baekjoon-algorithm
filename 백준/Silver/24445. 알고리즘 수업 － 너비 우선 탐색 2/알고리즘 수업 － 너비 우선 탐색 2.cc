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
int N, M, R;
vector<vector<int>> adj; // adjacency lsit

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> R;
    adj = vector<vector<int>>(N + 1);
    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> sorted(N + 1);
    vector<int> visited(N + 1);
    queue<int> q;
    q.push(R);
    int cnt = 1;
    visited[R] = cnt++;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(!sorted[node]) {
            sorted[node] = true;
            sort(adj[node].begin(), adj[node].end(), greater<int>());
        }
        for(int i = 0; i < adj[node].size(); i++) {
            int next_node = adj[node][i];
            if(!visited[next_node]) {
                visited[next_node] = cnt++;
                q.push(next_node);
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }
    
    return 0;
}