#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

const int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> v, dist;
vector<vector<bool>> visited;
int n;

bool checkRange(int y, int x, int n) {
    return y >= 0 && x >= 0 && y < n && x < n;
}

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-v[0][0], {0, 0}});
    visited[0][0] = true;
    dist[0][0] = v[0][0];
    while(!pq.empty()) {
        int d = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        // cout << y << ' ' << x << endl;
        pq.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + r[i][0];
            int nx = x + r[i][1];
            if(!checkRange(ny, nx, n)) continue;
            if(v[ny][nx] + d < dist[ny][nx]) {
                dist[ny][nx] = v[ny][nx] + d;
                pq.push({-dist[ny][nx], {ny, nx}});
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    int test_case =  1;
    while (true)
    {
        cin >> n;
        if(n == 0) break;

        v = vector<vector<int>>(n, vector<int>(n));
        dist = vector<vector<int>>(n, vector<int>(n, INF));
        visited = vector<vector<bool>>(n, vector<bool>(n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> v[i][j];
                // v[i][j] = 10;
            }
        }

        dijkstra();
        
        cout << "Problem " << test_case << ": " << dist[n-1][n-1] << '\n';

        test_case++;
    }
    
    return 0;
}