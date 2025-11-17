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

int N, M;
vector<int> v;
vector<int> sumarr;
int dp[21][21];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    v = vector<int>(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sumarr = vector<int>(N + 1);
    for(int i = 0; i < N; i++) {
        sumarr[i+1] = sumarr[i] + v[i]; // i~j => sumarr[j+1] - sumarr[i]
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j] = -INF;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            for(int k = i; k <= j; k++) {
                for(int l = k; l <= j; l++) {
                    dp[i][j] = max(dp[i][j], sumarr[l+1]-sumarr[k]);
                }
            }
        }
    }
    vector<int> index(N-1);
    for(int i = 0; i < M-1; i++) {
        index[i] = 1;
    }
    int ans = -INF;
    do {
        int ret = 0;
        int left = 0;
        int right = 0;
        while(right < N-1) {
            if(index[right] == 1) {
                ret += dp[left][right];
                left = right+1;
            }
            right++;
        }
        ret += dp[left][right];
        ans = max(ans, ret);
    }while(prev_permutation(index.begin(), index.end()));
    cout << ans << endl;
    return 0;
}
