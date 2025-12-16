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
// #define DEBUG
// #define MOD 1000000009

using namespace std;

/*
백준 16946 벽 부수고 이동하기4 23:14


*/
constexpr int ry[4] = {0, -1, 0, 1};
constexpr int rx[4] = {-1, 0, 1, 0};
constexpr int MAX_N = 1000;
constexpr int MAX_M = 1000;
constexpr int MOD = 10;
int N, M;
vector<vector<int>> v;
vector<vector<int>> area;
int arr[MAX_N * MAX_M];
int real_area[MAX_N * MAX_M];

int getParent(int a) {
    if(arr[a] != a) return arr[a] = getParent(arr[a]);
    return a;
}

void unionParent(int a, int b) {
    if(a > b) swap(a, b);
    int pa = getParent(a);
    int pb = getParent(b);
    if(pa != pb) arr[b] = pa;
}

inline bool checkRange(int y, int x) {
    return y >= 0 && x >= 0 && y < N && x < M;
}

void initArea() {
    area = vector<vector<int>>(N, vector<int>(M, -1));
    vector<vector<bool>> visited;
    visited = vector<vector<bool>>(N, vector<bool>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(v[i][j] == 0 && !visited[i][j]) {
                // make area
                queue<pii> q;
                q.push({i, j});
                int root = i*M + j;
                area[i][j] = getParent(root);
                // cout << "A: " << area[i][j] << endl;
                int cnt = 1;
                visited[i][j] = true;
                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for(int l = 0; l < 4; l++) {
                        int ny = ry[l] + y;
                        int nx = rx[l] + x;
                        if(!checkRange(ny, nx) || visited[ny][nx] || v[ny][nx] == 1) continue;
                        area[ny][nx] = getParent(ny*M + nx);
                        cnt++;
                        visited[ny][nx] = true;
                        unionParent(root, ny*M + nx);
                        q.push({ny, nx});
                    }

                }
                real_area[getParent(root)] = cnt;
            }
        }
    }
}

void solve() {
    vector<vector<int>> ans(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(v[i][j] == 1) {
                int cnt = 1;
                set<int> s;
                for(int l = 0; l < 4; l++) {
                    int ny = i + ry[l];
                    int nx = j + rx[l];
                    if(!checkRange(ny, nx)) continue;
                    if(area[ny][nx] != -1) {
                        int number = getParent(area[ny][nx]);
                        if(s.find(number) != s.end()) continue;
                        s.insert(number);
                        // cout << number << ' ' << real_area[number] << endl;
                        cnt += real_area[number];
                    }
                }
                ans[i][j] = cnt;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << ans[i][j] % MOD;
        }cout << '\n';
    }
}


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < MAX_N * MAX_M; i++) arr[i] = i;
    cin >> N >> M;
    string s;
    v = vector<vector<int>>(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        cin >> s;
        for(int j = 0; j < M; j++) {
            v[i][j] = s[j] - '0';
        }
    }

    initArea();
    solve();
    
    return 0;
}