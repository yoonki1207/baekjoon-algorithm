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
int N, M, T;
int arr[51][51];

inline vector<pii> nearCoords(const int y, const int x) {
    vector<pii> ret;
    for(int i = 0; i < 4; i++) {
        int ny = y + r[i][0];
        int nx = x + r[i][1];
        if(ny > N || ny < 1) continue;
        if(nx > M) nx = 1;
        if(nx < 1) nx = M;
        ret.push_back({ny, nx});
    }
    return ret;
}

bool solve() {
    vector<vector<bool>> visited;
    visited = vector<vector<bool>>(N+1, vector<bool>(M+1));
    bool erased = false;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j] != 0 && visited[i][j] == false) {
                int val = arr[i][j];
                queue<pii> q;
                visited[i][j] = true;
                q.push({i, j});
                bool isOnly = true;
                while(!q.empty()) {
                    int y = q.front().first, x = q.front().second;
                    q.pop();
                    vector<pii> res = nearCoords(y, x);
                    for(auto v: res) {
                        int ny = v.first, nx = v.second;
                        if(visited[ny][nx] || arr[ny][nx] != val) continue;
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                        isOnly = false;
                    }
                }
                if(isOnly) {
                    visited[i][j] = false;
                } else {
                    erased = true;
                }
            }
        }
    }
    for(int i = 1; i<= N; i++) {
        for(int j = 1; j<= M; j++) {
            if(visited[i][j]) arr[i][j] = 0;
        }
    }
    return erased;
}

void averaging() {
    double avg = 0;
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j]) {
                avg += arr[i][j];
                cnt++;
            }
        }
    }
    avg /= cnt;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j]) {
                if(avg < arr[i][j]) {
                    arr[i][j]--;
                } else if(avg > arr[i][j]) {
                    arr[i][j]++;
                }
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    int x, d, k;
    for(int test_case = 1; test_case <= T; test_case++) {
        cin >> x >> d >> k;
        for(int n = x; n <= N; n += x) {
            if(d == 0) {
                for(int l = 0; l < k; l++) {
                    int tmp = arr[n][M];
                    for(int i = M; i > 1; i--) {
                        arr[n][i] = arr[n][i-1];
                    }
                    arr[n][1] = tmp;
                }
            } else {
                for(int l = 0; l < k; l++) {
                    int tmp = arr[n][1];
                    for(int i = 1; i < M; i++) {
                        arr[n][i] = arr[n][i+1];
                    }
                    arr[n][M] = tmp;
                }
            }
        }
        bool erased = solve();
        if(!erased) {
            averaging();
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j]) {
                ans += arr[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
