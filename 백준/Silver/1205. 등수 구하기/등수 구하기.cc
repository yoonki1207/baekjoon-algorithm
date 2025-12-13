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

int N, P, new_score;
vector<int> v;
vector<int> ranking;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> new_score >> P;
    v = vector<int>(N+1);
    ranking = vector<int>(N+1);
    v[0] = new_score;
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    ranking[N] = 1;
    int cur_rank = 1;
    for(int i = N-1; i >= 0; i--) {
        if(v[i] != v[i+1]) {
            cur_rank = N-i+1;
        }
        ranking[i] = cur_rank;
    }
    
    auto iter = lower_bound(v.begin(), v.end(), new_score);
    int ans = ranking[iter - v.begin()];
    if(v.end() - iter > P) ans = -1;
    cout << ans;

    return 0;
}