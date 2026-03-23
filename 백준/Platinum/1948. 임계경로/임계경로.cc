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
int N, M, START_POINT, END_POINT;
vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, int>>> rev_adj;
vector<int> indegree;
vector<int> time_cost;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int u, v, w;
    cin >> N;
    cin >> M;
    adj = vector<vector<pair<int, int>>>(N + 1);
    rev_adj = vector<vector<pair<int, int>>>(N + 1);
    indegree = vector<int>(N + 1);
    time_cost = vector<int>(N + 1);
    for(int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        rev_adj[v].push_back({u, w});
        indegree[v]++;
    }
    cin >> START_POINT >> END_POINT;
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(vector<pair<int, int>>::iterator iter = adj[front].begin(); iter != adj[front].end(); ++iter) {
            indegree[iter->first]--;
            time_cost[iter->first] = max(time_cost[iter->first], iter->second + time_cost[front]);
            
            if(indegree[iter->first] == 0) {
                q.push(iter->first);
            }
        }
    }

    vector<bool> visited(N+1, false);
    queue<pair<int, int>> pair_q;
    int road_cnt = 0;
    pair_q.push({END_POINT, time_cost[END_POINT]});
    while(!pair_q.empty()) {
        int node = pair_q.front().first;
        int t = pair_q.front().second;
        pair_q.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for(vector<pair<int, int>>::iterator iter = rev_adj[node].begin(); iter != rev_adj[node].end(); iter++) {
            if(time_cost[iter->first] + iter->second == t) {
                pair_q.push({iter->first, t - iter->second});
                road_cnt++;
            }
        }
    }

    cout << time_cost[END_POINT] << '\n';
    cout << road_cnt << endl;
    
    return 0;
}