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
#include <random>
#define INF 987654321
#define lld long long int
#define pii pair<int, int>
#define pdd pair<double, double>
// #define DEBUG
// #define MOD 1000000009

using namespace std;
int T, W;
int info[1001];
int dp[1001][31][2];

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T >> W;
    int x;
    for(int i = 0; i < T; i++) {
        cin >> x;
        info[i] = x;
    }
    int dn = info[0];
    dp[0][0][0] = dn == 1 ? 1 : 0;
    if(W >= 1) {
        dp[0][1][1] = dn == 2 ? 1 : 0;
    }
    for(int i = 1; i < T; i++) {
        int drop_n = info[i];
        if(drop_n == 1) {
            dp[i][0][0] = dp[i-1][0][0] + 1;
        } else {
            dp[i][0][0] = dp[i-1][0][0];
        }
    }
    for(int m = 1; m <= W; m++) {
        for(int i = 1; i < T; i++) {
            int drop_n = info[i];
            if(drop_n == 1) {
                dp[i][m][0] = max(dp[i-1][m][0], dp[i-1][m-1][1]) + 1;
                dp[i][m][1] = max(dp[i-1][m][1], dp[i-1][m-1][0]);
            } else {
                dp[i][m][0] = max(dp[i-1][m][0], dp[i-1][m-1][1]);
                dp[i][m][1] = max(dp[i-1][m][1], dp[i-1][m-1][0]) + 1;
            }
        }
    }
    int ans = 0;
    for(int m = 0; m <= W; m++) {
        ans = max(ans, dp[T-1][m][0]);
        ans = max(ans, dp[T-1][m][1]);
    }
    cout << ans << endl;
    return 0;
}