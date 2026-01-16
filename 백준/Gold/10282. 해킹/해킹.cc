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

int T;
vector < vector<pair<int, int>>> v;

vector<int> dijkstra(const int start_node) {
    vector<int> dist(v.size(), INF);
    dist[start_node] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start_node });
    while (!pq.empty()) {
        int d = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (dist[node] < d) continue;
        for (int i = 0; i < v[node].size(); i++) {
            int nd = v[node][i].second;
            int nn = v[node][i].first;
            if (d + nd < dist[nn]) {
                dist[nn] = d + nd;
                pq.push({-dist[nn], nn});
            }
        }
    }
    return dist;
}

int getTime(vector<int>& dist) {
    int ret = 0;
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] != INF) {
            ret = max(ret, dist[i]);
        }
    }
    return ret;
}

int getComputer(vector<int>& dist) {
    int cnt = 0;
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] != INF) cnt++;
    }
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    /* input */
    cin >> T;
    int n, d, c;
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> n >> d >> c;
        v = vector<vector<pair<int, int>>>(n + 1);
        int a, b, s;
        for (int i = 0; i < d; i++) {
            cin >> a >> b >> s;
            v[b].push_back({ a, s });
        }
        vector<int> dist = dijkstra(c);
        int num = getComputer(dist);
        int t = getTime(dist);
        cout << num << ' ' << t << '\n';

    }

    return 0;
}