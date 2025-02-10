#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

bool cache[600000];

/**
0 0 0
0 0 0

0 0 0
0 0

0 0
0 0 0
 */
int solve4(int arr[][2], int n, int W) {
    int dp[10000][3] = {0};
    if(arr[0][1] + arr[n-1][1] > W || arr[0][0] + arr[n-1][0] > W || n == 1) return INF;
    dp[0][0] = 2;
    dp[0][1] = dp[0][2] = 1;
    for(int i = 1; i < n; i++) {
        dp[i][0] = ((arr[i][0]+arr[i][1]) <= W ? 1 : 2) + dp[i-1][0];  
        if(arr[i][0] + arr[i-1][0] <= W && arr[i][1] + arr[i-1][1] <= W && i > 2) {
            dp[i][0] = min(dp[i][0], i > 2 ? dp[i-2][0] + 2 : 2);
        } 
        if(arr[i-1][1] + arr[i][1] <= W && i > 1) {
            dp[i][0] = min(dp[i][0], dp[i-1][1] + 2);
        }
        if(arr[i-1][0] + arr[i][0] <= W && i > 1) {
            dp[i][0] = min(dp[i][0], dp[i-1][2] + 2);
        }
        if((arr[i-1][1] + arr[i][1] <= W) && (arr[i-1][0] + arr[i][0] <= W)) {
            dp[i][0] = min(dp[i][0], dp[i-1][0] + 2);
        }
        dp[i][1] = dp[i-1][0] + 1;
        if(arr[i][0] + arr[i-1][0] <= W && i > 1) {
            dp[i][1] = min(dp[i][1], dp[i-1][2] + 1);
        }
        dp[i][2] = dp[i-1][0] + 1;
        if(arr[i][1] + arr[i-1][1] <= W && i > 1) {
            dp[i][2] = min(dp[i][2], dp[i-1][1] + 1);
        }
    }
    return dp[n-2][0];
}

int solve3(int arr[][2], int n, int W) {
    int dp[10000][3] = {0};
    if(arr[0][1] + arr[n-1][1] > W || n == 1) return INF;
    dp[0][0] = 2;
    dp[0][1] = dp[0][2] = 1;
    for(int i = 1; i < n; i++) {
        dp[i][0] = ((arr[i][0]+arr[i][1]) <= W ? 1 : 2) + dp[i-1][0]; 
        if(arr[i][0] + arr[i-1][0] <= W && arr[i][1] + arr[i-1][1] <= W && i > 2) {
            dp[i][0] = min(dp[i][0], i > 2 ? dp[i-2][0] + 2 : 2);
        } 
        if(arr[i-1][1] + arr[i][1] <= W && i > 1) {
            dp[i][0] = min(dp[i][0], dp[i-1][1] + 2);
        }
        if(arr[i-1][0] + arr[i][0] <= W) {
            dp[i][0] = min(dp[i][0], dp[i-1][2] + 2);
        }
        if((arr[i-1][1] + arr[i][1] <= W) && (arr[i-1][0] + arr[i][0] <= W)) {
            dp[i][0] = min(dp[i][0], dp[i-1][0] + 2);
        }
        dp[i][1] = dp[i-1][0] + 1;
        if(arr[i][0] + arr[i-1][0] <= W) {
            dp[i][1] = min(dp[i][1], dp[i-1][2] + 1);
        }
        dp[i][2] = dp[i-1][0] + 1;
        if(arr[i][1] + arr[i-1][1] <= W && i > 1) {
            dp[i][2] = min(dp[i][2], dp[i-1][1] + 1);
        }
    }
    return dp[n-1][1];
}

int solve2(int arr[][2], int n, int W) {
    int dp[10000][3] = {0};
    if(arr[0][0] + arr[n-1][0] > W || n == 1) return INF;
    dp[0][0] = 2;
    dp[0][1] = dp[0][2] = 1;
    for(int i = 1; i < n; i++) {
        dp[i][0] = ((arr[i][0]+arr[i][1]) <= W ? 1 : 2) + dp[i-1][0]; 
        if(arr[i][0] + arr[i-1][0] <= W && arr[i][1] + arr[i-1][1] <= W && i > 2) {
            dp[i][0] = min(dp[i][0], i > 2 ? dp[i-2][0] + 2 : 2);
        } 
        if(arr[i-1][1] + arr[i][1] <= W) {
            dp[i][0] = min(dp[i][0], dp[i-1][1] + 2);
        }
        if(arr[i-1][0] + arr[i][0] <= W && i > 1) {
            dp[i][0] = min(dp[i][0], dp[i-1][2] + 2);
        }
        if((arr[i-1][1] + arr[i][1] <= W) && (arr[i-1][0] + arr[i][0] <= W)) {
            dp[i][0] = min(dp[i][0], dp[i-1][0] + 2);
        }
        dp[i][1] = dp[i-1][0] + 1;
        if(arr[i][0] + arr[i-1][0] <= W && i > 1) {
            dp[i][1] = min(dp[i][1], dp[i-1][2] + 1);
        }
        dp[i][2] = dp[i-1][0] + 1;
        if(arr[i][1] + arr[i-1][1] <= W) {
            dp[i][2] = min(dp[i][2], dp[i-1][1] + 1);
        }
    }
    return dp[n-1][2];
}

int solve1(int arr[][2], int n, int W) {
    int dp[10000][3] = {0};
    dp[0][0] = (arr[0][0] + arr[0][1] <= W) ? 1 : 2;
    dp[0][1] = dp[0][2] = 1;
    for(int i = 1; i < n; i++) {
        dp[i][0] = ((arr[i][0]+arr[i][1]) <= W ? 1 : 2) + dp[i-1][0];
        if(arr[i][0] + arr[i-1][0] <= W && arr[i][1] + arr[i-1][1] <= W) {
            dp[i][0] = min(dp[i][0], i >= 2 ? dp[i-2][0] + 2 : 2);
        } 
        if(arr[i-1][1] + arr[i][1] <= W) {
            dp[i][0] = min(dp[i][0], dp[i-1][1] + 2);
        }
        if(arr[i-1][0] + arr[i][0] <= W) {
            dp[i][0] = min(dp[i][0], dp[i-1][2] + 2);
        }
        if((arr[i-1][1] + arr[i][1] <= W) && (arr[i-1][0] + arr[i][0] <= W)) {
            dp[i][0] = min(dp[i][0], dp[i-1][0] + 2);
        }

        dp[i][1] = dp[i-1][0] + 1;
        if(arr[i][0] + arr[i-1][0] <= W) {
            dp[i][1] = min(dp[i][1], dp[i-1][2] + 1);
        }

        dp[i][2] = dp[i-1][0] + 1;
        if(arr[i][1] + arr[i-1][1] <= W) {
            dp[i][2] = min(dp[i][2], dp[i-1][1] + 1);
        }
    }
    // cout <<"dp" << endl;
    // for(int i = 0; i < n; i++) {
    //     cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
    // }
    return dp[n-1][0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    // vector<int> v;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        int n, W;
        cin >> n >> W;
        int arr[10000][2];
        // case 1:
        for(int i = 0; i < n; i++) {
            cin >> arr[i][0];
        }
        for(int i = 0; i < n; i++) {
            cin >> arr[i][1];
        }
        int s1 = solve1(arr, n, W);
        int s2 = solve2(arr, n, W);
        int s3 = solve3(arr, n, W);
        int s4 = solve4(arr, n, W);
        // cout << s1 << endl;
        // cout << s2 << endl;
        // cout << s3 << endl;
        // cout << s4 << endl;
        int ans = min(s1, min(s2, min(s3, s4)));
        cout << ans << '\n';
        // v.push_back(ans);

    }

    // for(int i = 0; i < v.size(); i++) {
    //     cout << v[i] << ' ';
    // }
    return 0;
}