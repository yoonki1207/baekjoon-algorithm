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
constexpr int MAX_X = 100001;
int N;
vector<int> arr;
vector<int> cnt;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    arr = vector<int>(N);
    cnt = vector<int>(MAX_X, 0);
    for(int i = 0; i < N; i++) cin >> arr[i];
    int pl = -1, pr = -1;
    int l = 0, r = 0;
    lld ans = 0;
    ++cnt[arr[0]];
    while(r < N) {
        if(r + 1 < N) {
            if(l > r) {
                ++r;
                ++cnt[arr[r]];
            }
            else if(cnt[arr[r+1]] == 0) {
                ++r;
                ++cnt[arr[r]];
            } else {
                lld d = r - l + 1;
                ans += d*(d+1)/2;
                if(pr != -1 && l <= pr) {
                    // 0 1 2 / 1 2 3 -> 1 2
                    d = pr - l + 1;
                    ans -= d*(d+1)/2;
                }
                pl = l;
                pr = r;
                --cnt[arr[l]];
                ++l;
            }
        } else {
            break;
        }
    }
    lld d = r - l + 1;
    ans += d*(d+1)/2;
    if(pr != -1 && l <= pr) {
        d = pr - l + 1;
        ans -= d*(d+1)/2;
    }
    cout << ans << '\n';
    return 0;
}