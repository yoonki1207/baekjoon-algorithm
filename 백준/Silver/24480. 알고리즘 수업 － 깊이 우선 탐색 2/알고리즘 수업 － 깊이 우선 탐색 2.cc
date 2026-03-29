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
#include <random>
#define INF 987654321
#define lld long long int
#define pii pair<int, int>
#define pdd pair<double, double>
// #define DEBUG
// #define MOD 1000000009

using namespace std;

int N, M, R;
vector<vector<int>> v;
vector<int> pos;

void dfs(int node, vector<bool>& visited, int& cnt) {
    for(int i = 0; i < v[node].size(); i++) {
        if(!visited[v[node][i]]) {
            visited[v[node][i]] = true;
            pos[v[node][i]] = ++cnt;
            dfs(v[node][i], visited, cnt);
        }
    }
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> R;
    int a, b;
    v = vector<vector<int>>(N + 1);
    pos = vector<int>(N + 1);
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= N; i++) {
        sort(v[i].begin(), v[i].end(), greater<int>());
    }
    vector<bool> visited(N + 1);
    visited[R] = true;
    pos[R] = 1;
    int cnt = 1;
    dfs(R, visited, cnt);
    for(int i = 1; i <= N; i++) {
        cout << pos[i] << '\n';
    }

    return 0;
}