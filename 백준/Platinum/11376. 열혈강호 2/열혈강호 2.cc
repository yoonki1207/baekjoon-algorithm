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
백준 12781
*/
int N, M;
vector<vector<int>> v;
vector<int> matched;
vector<bool> visited;
bool dfs(int p) {
    for(int i = 0; i < v[p].size(); i++) {
        int next_work = v[p][i];
        if(visited[next_work]) continue;
        visited[next_work] = true;
        int owner = matched[next_work];
        if(owner >= 0) {
            if(dfs(owner)) {
                matched[next_work] = p;
                return true;
            }
        } else {
            matched[next_work] = p;
            return true;
        }
    }
    return false;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    v = vector<vector<int>>(N);
    matched = vector<int>(M + 1, -1);
    visited = vector<bool>(M + 1);
    int len;
    for (int i = 0; i < N; i++) {
        cin >> len;
        v[i] = vector<int>(len);
        for(int j = 0; j < len; j++) {
            cin >> v[i][j];
        }
    }
    int cnt = 0;
    for(int p = 0; p < N; p++) {
        fill(visited.begin(), visited.end(), false);
        if(dfs(p))++cnt;
    }
    for(int p = 0; p < N; p++) {
        fill(visited.begin(), visited.end(), false);
        if(dfs(p))++cnt;
    }
    cout << cnt;
    return 0;
}