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
백준 
*/
constexpr int START_NODE = 1;
constexpr int DESTINATION_NODE = 2;
constexpr int MAX_N = 401;
int N, P;
int visited[MAX_N][MAX_N];
vector<vector<int>> v;
int owner[MAX_N][MAX_N];
int pre[MAX_N];
int capacity[MAX_N][MAX_N];
int flow[MAX_N][MAX_N];

int solve() {
    int ans = 0;
    while(true) {
        queue<int> q;
        memset(pre, -1, sizeof(pre));
        q.push(START_NODE);
        int curr = 0;
        while(!q.empty()) {
            curr = q.front();
            q.pop();
            for(int next: v[curr]) if (flow[curr][next] < capacity[curr][next] && pre[next] == -1) {
                pre[next] = curr;
                q.push(next);
                if(next == DESTINATION_NODE) break;
            }
        }
        if(pre[DESTINATION_NODE] == -1) break;
        int f = 1e9;
        for (int i = DESTINATION_NODE; i != START_NODE; i = pre[i]) { // 역추적
            f = min(f, capacity[pre[i]][i] - flow[pre[i]][i]); // 가용 유량 계산
        }
        for (int i = DESTINATION_NODE; i != START_NODE; i = pre[i]) {
            flow[pre[i]][i] += f; // 정방향 갱신
            flow[i][pre[i]] -= f; // 역방향 갱신
        }
        ans += f;
    }
    return ans;
}

void Input() {
    cin >> N >> P;
    v = vector<vector<int>>(N + 1);
    int a, b;
    for (int i = 0; i < P; ++i) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        capacity[a][b] = 1;
    }
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Input();
    int cnt = 0;
    cnt = solve();
    
    cout << cnt << endl;
    return 0;
}
