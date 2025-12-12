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

constexpr int MAX_N = 1001;
int lis[MAX_N];
int N;
vector<int> v;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    v = vector<int>(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    vector<int> tmp;
    tmp.push_back(v[0]);
    lis[0] = tmp.size();
    for(int i = 1; i < N; i++) {
        auto iter = lower_bound(tmp.begin(), tmp.end(), v[i]);
        if(iter == tmp.end()) {
            tmp.push_back(v[i]);
        } else {
            *iter = v[i];
        }
        lis[i] = tmp.size();
    }
    int ans = 1;
    tmp.clear();
    tmp.push_back(v[N-1]);
    for(int i = N-2; i >= 0; i--) {
        auto iter = lower_bound(tmp.begin(), tmp.end(), v[i]);
        if(iter == tmp.end()) {
            tmp.push_back(v[i]);
        } else {
            *iter = v[i];
        }
        ans = max(ans, lis[i] + (int)tmp.size() - 1);
    }
    cout << ans;



    return 0;
}

// 0 1 2 3 4 5 6 7
