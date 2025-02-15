#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

const int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> v;
vector<vector<int>> dist;
vector<vector<int>> ans;
int n,m;

void solve() {
    for(int transit = 1; transit <= n; transit++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][j] > dist[i][transit] + dist[transit][j]) {
                    dist[i][j] = dist[i][transit] + dist[transit][j];
                    ans[i][j] = ans[i][transit];
                }
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    cin >> n >> m;

    v = vector<vector<int>>(n+1, vector<int>(n+1));
    dist = vector<vector<int>>(n+1, vector<int>(n+1, INF));
    ans = vector<vector<int>>(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (i != j) ans[i][j] = j;
        }
    }

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a][b] = v[b][a] = c;
        dist[a][b] = dist[b][a] = c;
    }

    solve();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                cout << "- ";
            } else {
                cout << ans[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}