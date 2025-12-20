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
백준 2482 색상환


*/
constexpr int MAX_N = 1001;
constexpr int MOD = 1'000'000'003;
int N, K;
int dp[MAX_N][MAX_N];

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    int result = 0;
    for(int i = 0; i <= N; i++) {
        dp[i][1] = i;
    }
    for(int i = 2; i <= N; i++) {
        for(int j = 2; j <= K; j++) {
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
        }
    }
    cout << (K == 1 ? N : dp[N-3][K-1] + dp[N-1][K]) % MOD;
    return 0;
}