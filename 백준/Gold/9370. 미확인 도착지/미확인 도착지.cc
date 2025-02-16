#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

int n, m, t, s, g, h; // g != h
vector<vector<pair<int, int>>> v;

vector<int> dijkstra(int start_point) {
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n+1, INF);

    pq.push({0, start_point});
    dist[start_point] = 0;
    while(!pq.empty()) {
        int d = -pq.top().first;
        int x = pq.top().second;
        pq.pop();
        for(vector<pair<int, int>>::iterator iter = v[x].begin();
            iter != v[x].end();
            ++iter) {
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
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        v = vector<vector<pair<int, int>>>(n+1);
        int ghDist = INF;
        for(int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            v[a].push_back({b, d});
            v[b].push_back({a, d});
            if((a==g && b ==h) || (a==h && b ==g)) ghDist = d;
        }
        vector<int> distS = dijkstra(s);
        vector<int> distG = dijkstra(g);
        vector<int> distH = dijkstra(h);
        vector<int> ans;
        for(int i = 0; i < t; i++) {
            int x;
            cin >> x; // x != s
            if((distS[x] == distS[g] + distG[h] + distH[x])
                || (distS[x] == distS[h] + distH[g] + distG[x])) {
                ans.push_back(x);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }cout << endl;
    }

    return 0;
}