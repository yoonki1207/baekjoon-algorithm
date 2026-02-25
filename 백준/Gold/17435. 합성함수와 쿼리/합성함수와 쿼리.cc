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
백준 17435
*/
constexpr int MAX_LOG = 20;
constexpr int MAX_X = 200001;
int N, Q;
vector<int> arr;
int dp[MAX_LOG][MAX_X];

void init() {
    for(int x = 1; x <= N; x++) {
        dp[0][x] = arr[x];
    }
    for(int i = 1; i < MAX_LOG; i++) {
        for(int x = 1; x <= N; x++) {
            int k = x;
            for(int j = i-1; j >= 0; j--) {
                k = dp[j][k];
            }
            dp[i][x] = dp[0][k];
        }
    }
}

int getFunction(int n, int x) {
    if(n == 1) return arr[x];
    int k = x;
    int ret = 0;
    for(int i = 0; i < MAX_LOG; i++) {
        if(n & (1 << i)) {
            k = dp[i][k];
        }
    }
    return k;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    arr = vector<int>(N + 1);
    for(int i = 1; i <= N; i++) cin >> arr[i];
    cin >> Q;
    init();
    int a, b;
    for(int i = 0; i < Q; i++) {
        cin >> a >> b;
        cout << getFunction(a, b) << '\n';
    }
    return 0;
}
