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
#define MAX_N 32001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG
#define MOD 1000000009

using namespace std;

const int r[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; // UP DOWN RIGHT LEFT
char cave[101][101];

int R, C, N;

bool checkRange(int y, int x) {return x >= 0 && y >= 0 && y < R && x < C;}

void drop(int y, int x) {
    // cout << "drop from " << y << ' ' << x << endl;
    vector<vector<bool>> visited(R, vector<bool>(C));
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    q.push({y, x});
    v.push_back({y, x});
    visited[y][x] = true;
    while(!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + r[i][0];
            int nx = x + r[i][1];
            if(checkRange(ny, nx) == false || visited[ny][nx] || cave[ny][nx] == 0) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
            v.push_back({ny, nx});
        }
    }
    for(int i = 0; i < v.size(); i++) {
        cave[v[i].first][v[i].second] = 0;
    }
    int flag = 0;
    for(int offset = 0; flag == 0 ; offset++) {
        for(vector<pair<int, int>>::iterator iter = v.begin(); iter != v.end(); iter++) {
            if(iter->first + offset == R || cave[iter->first + offset][iter->second] == 1) {
                flag = offset;
                break;
            }
        }
    }
    // cout << "Dropper size is: " << v.size() << endl;
    for(vector<pair<int, int>>::iterator iter = v.begin(); iter != v.end(); iter++) {
        cave[iter->first + flag-1][iter->second] = 1;
    }
}

void gravity(int cy, int cx) {
    for(int w = 0; w < 4; w++) {
        int i = cy + r[w][0];
        int j = cx + r[w][1];
        if(checkRange(i, j) && cave[i][j] == 1) {
            vector<vector<bool>> visited(R, vector<bool>(C));
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            bool isair = i != R-1;
            while(!q.empty()) {
                int y = q.front().first, x = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int ny = y + r[k][0], 
                        nx = x + r[k][1];
                    if(checkRange(ny, nx) == false || visited[ny][nx] || cave[ny][nx] == 0) continue;
                    visited[ny][nx] = true;
                    if(ny == R-1) isair = false;
                    q.push({ny, nx});
                }
            }

            if(isair) {
                // drop
                drop(i, j);
                return;
            } else {
            }
        }
    }
}

void destoryFromLeft(int height) {
    int row = R-height;
    for(int i = 0; i < C; i++) {
        if(cave[row][i]) {
            // cout << "Hit at " << row << ' ' << i << endl;
            cave[row][i] = 0;
            gravity(row, i);
            break;
        }
    }
}

void destoryFromRight(int height) {
    int row = R-height;
    for(int i = C-1; i >= 0; i--) {
        if(cave[row][i]) {
            // cout << "Hit at " << row << ' ' << i << endl;
            cave[row][i] = 0;
            gravity(row, i);
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> R >> C;
    string s;
    for(int i = 0; i < R; i++) {
        cin >> s;
        for(int j = 0; j < C; j++) {
            if(s[j] == '.') cave[i][j] = 0;
            else cave[i][j] = 1;
        }
    }
    cin >> N;
    vector<int> xs;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        xs.push_back(x);
    }
    for(int i = 0; i < N; i++) {
        int x = xs[i];
        if(i % 2 == 0) {
            destoryFromLeft(x);
        } else {
            destoryFromRight(x);
        }
    }
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << (cave[i][j] == 0 ? '.' : 'x');
        }
        cout << '\n';
    }
    return 0;
}

/*

7 6
......
......
xx....
.xx...
..xx..
...xx.
....x.
4
6 4 1 1


8 8
........
........
...x.xx.
...xxx..
..xxx...
..x.xxx.
..x...x.
.xxx..x.
5
6 6 4 3 1
[1246ms]
*/