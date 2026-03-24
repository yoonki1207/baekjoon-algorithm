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
int N;
vector<int> dp;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    dp = vector<int>(N + 1);
    dp[0] = 1;
    dp[1] = 3;
    for(int i = 2; i < N; i++) {
        dp[i] = (dp[i-1] + dp[i-2] * 2) % 10007;
    }
    cout << dp[N-1] << endl;
    return 0;
}