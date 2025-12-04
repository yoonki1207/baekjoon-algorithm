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
#define MOD 1000000009

using namespace std;

/*
백준 2186 문자판
그냥 DFS
+ memozation

[condition]
1 <= N, M <= 100
1 <= K <= 5
모두 대문자
1~80자 영단어
*/

constexpr int offset_y[4] = {0, 0, 1, -1};
constexpr int offset_x[4] = {-1, 1, 0, 0};
constexpr int KEYWORD_MAX = 80;
int N, M, K;
vector<vector<char>> arr;
vector<vector<vector<int>>> cache;
string keyword;

inline bool checkRange(int y, int x) {return x >= 0 && y >= 0 && x < M && y < N;}
int dfs(int y, int x, int index) {
    if(index == keyword.size()) return 1;
    if(cache[y][x][index] != -1) return cache[y][x][index];
    int ret = 0;
    for(int dir = 0; dir < 4; dir++) {
        for(int k = 1; k <= K; k++) {
            const int ny = y + offset_y[dir] * k;
            const int nx = x + offset_x[dir] * k;
            if(!checkRange(ny, nx)) continue;
            if(arr[ny][nx] == keyword[index]) {
                ret += dfs(ny, nx, index + 1);
            }
        }
    }
    return cache[y][x][index] = ret;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    arr = vector<vector<char>>(N, vector<char>(M));
    cache = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(KEYWORD_MAX, -1)));
    string s;
    for(int i = 0; i < N; i++) {
        cin >> s;
        for(int j = 0; j < M; j++) {
            arr[i][j] = s[j];
        }
    }
    cin >> keyword;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] == keyword[0]) {
                ans += dfs(i, j, 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
