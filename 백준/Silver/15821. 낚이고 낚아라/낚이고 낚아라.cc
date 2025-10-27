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
#define INF 987654321
#define MAX_N 32001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG
#define MOD 1000000009

using namespace std;

int K, N, P;

lld squred_dist(lld x, lld y) {
    return x*x + y*y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N >> K;
    vector<long long> v;
    for(int i = 0; i < N; i++) {
        cin >> P;
        lld x, y;
        lld max_dist = 0;
        for(int j = 0; j < P; j++) {
            cin >> x >> y;
            max_dist = max(max_dist, squred_dist(x, y));
        }
        v.push_back(max_dist);
    }
    sort(v.begin(), v.end());
    cout << fixed;
    cout << setprecision(2);
    cout << (double)v[K-1];
    

    return 0;
}
