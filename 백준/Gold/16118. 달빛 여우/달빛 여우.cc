#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

int n, m;
vector<vector<pair<int, int>>> v;

vector<int> dijkstra2() {
    vector<int> dist[2];
    dist[0] = vector<int>(n+1, INF);
    dist[1] = vector<int>(n+1, INF);
    priority_queue<pair<int, pair<bool, int>>> pq;
    pq.push({0, {1, 1}});
    // dist[0][1] = dist[0][0] = 0;
    dist[1][1] = 0;
    while(!pq.empty()) {
        bool sprintReady = pq.top().second.first;
        int d = -pq.top().first;
        int u = pq.top().second.second;
        pq.pop();
        if(d > dist[(int)sprintReady][u]) continue;
        for(vector<pair<int, int>>::iterator iter = v[u].begin(); iter != v[u].end(); ++iter) {
            int& beforeDist = dist[(int)!sprintReady][iter->first];
            if(d + iter->second*(sprintReady?0.5:2) < beforeDist) {
                beforeDist = d + iter->second*(sprintReady?0.5:2);
                pq.push({-beforeDist, {!sprintReady, iter->first}});
            }
        }
    }
    vector<int> ret(n+1);
    for(int i = 1; i<=n ;i++) {
        ret[i] = min(dist[0][i], dist[1][i]);
        // cout << dist[0][i] << ' ' << dist[1][i] << endl;
    }
    return ret;
}

vector<int> dijkstra() {
    vector<int> dist(n+1, INF);
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()) {
        int d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for(vector<pair<int, int>>::iterator iter = v[u].begin(); iter != v[u].end(); iter++) {
            if(d + iter->second < dist[iter->first]) {
                dist[iter->first] = d + iter->second;
                pq.push({-dist[iter->first], iter->first});
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    cin >> n >> m;
    // priority_queue<pair<int,pair<int,int>>> w;
    // w.push({-1, {3, 1}});
    // w.push({-2, {2, 1}});
    // w.push({-3, {1, 1}});
    // cout << w.top().first << endl;
    v = vector<vector<pair<int, int>>>(n+1);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c*2});
        v[b].push_back({a, c*2});
    }
    vector<int> dist = dijkstra2();
    vector<int> ddist = dijkstra();
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] > ddist[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}