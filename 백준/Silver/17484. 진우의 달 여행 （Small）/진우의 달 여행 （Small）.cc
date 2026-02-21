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
백준 17484

*/
int N, M;
vector<vector<int>> v;
int dp[10][10][3];

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    v = vector<vector<int>>(N, vector<int>(M));
    // dp = vector<vector<int>>(N, vector<int>(M, INF));
    for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) for(int k = 0; k <3; k++) dp[i][j][k] = INF;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            dp[0][i][j] = v[0][i];
        }
    }
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(j-1 >= 0){
                dp[i][j][0] = min(dp[i][j][0], v[i][j] + dp[i-1][j-1][1]);
                dp[i][j][0] = min(dp[i][j][0], v[i][j] + dp[i-1][j-1][2]);
            }
            dp[i][j][1] =             min(dp[i][j][1], v[i][j] + dp[i-1][j][0]);
            dp[i][j][1] =             min(dp[i][j][1], v[i][j] + dp[i-1][j][2]);
            if(j+1 < M) {
                dp[i][j][2] = min(dp[i][j][2], v[i][j] + dp[i-1][j+1][0]);
                dp[i][j][2] = min(dp[i][j][2], v[i][j] + dp[i-1][j+1][1]);
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            ans = min(ans, dp[N-1][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
