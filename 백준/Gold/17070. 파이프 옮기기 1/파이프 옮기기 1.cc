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
#define pdd pair<double, double>
// #define DEBUG
// #define MOD 1000000009

using namespace std;

/*
백준 17070
*/
int N;
vector<vector<int>> v;

bool checkRange(int y, int x) {
    return x >= 0 && y >= 0 && x < N && y < N && v[y][x] == 0;
}

bool checkRange(int dir, int y, int x) {
    if(dir == 0 || dir == 2) {
        return checkRange(y, x);
    } else {
        return checkRange(y, x) && v[y-1][x] == 0 && v[y][x-1] == 0;
    }
}

int ans = 0;
void dfs(int dir, int y, int x) {
    if(y == N-1 && x == N-1) {
        ++ans;
        return;
    }
    if(dir == 0) {
        if(checkRange(y, x+1)) {
            dfs(0, y, x+1);
        } 
        if(checkRange(1, y+1, x+1)) {
            dfs(1, y+1, x+1);
        }
    } else if(dir == 1) {
        if(checkRange(y, x+1)) {
            dfs(0, y, x+1);
        }
        if(checkRange(1, y+1, x+1)) {
            dfs(1, y+1, x+1);
        }
        if(checkRange(y+1, x)) {
            dfs(2, y+1, x);
        }
    } else {
        if(checkRange(1, y+1, x+1)) {
            dfs(1, y+1, x+1);
        }
        if(checkRange(y+1, x)) {
            dfs(2, y+1, x);
        }
    }
}
int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    v = vector<vector<int>>(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    dfs(0, 0, 1);
    cout << ans;
    
    return 0;
}