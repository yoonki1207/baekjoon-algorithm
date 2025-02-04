#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#define INF 987654321

using namespace std;

int n, m;
int arr[10][10];
int trr[10][10];
int brr[7];
int bridge[7][7];
int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool checkRange(int y, int x) {
    return y>=0 && x >= 0 && y < n && x < m;
}

void setIsland(int y, int x, const int t) {
    trr[y][x] = t;
    for(int i = 0; i < 4;i ++) {
        int ny = y + r[i][0];
        int nx = x + r[i][1];
        if(checkRange(ny, nx) && arr[ny][nx] != 0 && trr[ny][nx] != t) {
            setIsland(ny, nx, t);
        }
    }
}

int labelIslands() {
    int islandNumber = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] != 0 && trr[i][j] == 0) {
                setIsland(i, j, islandNumber);
                islandNumber++;
            }
        }
    }
    return islandNumber - 1;
}

int isPossibleMakeBridge(int y, int x, int t) {
    int ret = INF;
    for(int i = 0; i < 4; i++) {
        int dret = 0;
        for(int j = 1; j < 10; j++, dret++) {
            int ny = y + r[i][0]*j;
            int nx = x + r[i][1]*j;
            if(!checkRange(ny, nx)) {
                dret = -1; break;
            }
            if(trr[ny][nx] == t) {
                break;
            }
            if(arr[ny][nx] != 0) {
                dret = -1; break;
            }
        }
        if(dret < 2) continue;
        ret = min(ret, dret);
    }
    return ret == INF ? -1 : ret;
}

int makeBridge(int a, int b) {
    if(a==b) return INF;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(trr[i][j] == a) {
                int len = isPossibleMakeBridge(i, j, b);
                if(len>0) bridge[a][b] = bridge[b][a] = min(bridge[a][b], len);
            }
        }
    }
    return bridge[a][b];
}

int getParent(int a) {
    if(a != brr[a]) brr[a] = getParent(brr[a]);
    return brr[a];
}

void unionNode(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);
    if(pa != pb) brr[pb] = getParent(pa);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 7; i++) for(int j = 0; j < 7; j++) bridge[i][j] = INF;
    for(int i = 0; i < 7; i++) brr[i] = i;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int numIslands = labelIslands();

    for(int i = 1; i <= numIslands; i++) {
        for(int j = i+1; j <= numIslands; j++) {
            makeBridge(i, j);
        }
    }
    vector<pair<int, pair<int, int>>> bridges;
    for(int i = 1; i <= numIslands; i++) {
        for(int j = i+1; j <= numIslands; j++) {
            if(bridge[i][j] != INF)
                bridges.push_back({bridge[i][j], {i, j}});
        }
    }

    sort(bridges.begin(), bridges.end());
    int ans = 0;
    for(int i = 0; i < bridges.size(); i++) {
        int len = bridges[i].first;
        int a = bridges[i].second.first;
        int b = bridges[i].second.second;
        if(getParent(a) != getParent(b)) {
            ans += len;
            unionNode(a, b);
        }
    }
    bool isPossible = true;
    int p = getParent(1);
    for(int i = 1; i <= numIslands; i++) {
        if(p != getParent(i)) isPossible = false;
    }
    if(!isPossible || ans == 0) ans = -1;
    cout << ans;
    return 0;
}