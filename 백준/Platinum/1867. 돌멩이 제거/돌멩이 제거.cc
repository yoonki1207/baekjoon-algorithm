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
백준 1867
*/
constexpr int MAX_N = 501;
int N, K;
vector<int> adj[MAX_N];
bool done[MAX_N];
int slt[MAX_N];

bool dfs(int x) {
    for (int i = 0; i < adj[x].size(); i++) {
        int p = adj[x][i];
        if (done[p]) continue;
        done[p] = true;
        if (slt[p] == 0 || dfs(slt[p])) {
            slt[p] = x;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    int r, c;
    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        adj[r].push_back(c);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        fill(done, done + MAX_N, false);
        if (dfs(i)) {
            cnt++;
        }
    }
    cout << cnt;


    return 0;
}