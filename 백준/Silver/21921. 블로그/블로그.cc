#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#include <set>
#define INF 987654321
#define lld long long
#define pii pair<int, int>

using namespace std;

int N, X;
vector<int> v;
vector<lld> prefix;

int main() {
    ios_base::sync_with_stdio(false);
    /* input */
    cin >> N >> X;
    v = vector<int>(N);
    prefix = vector<lld>(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        prefix[i + 1] += prefix[i] + v[i];
    }
    // prefix sum
    // prefix[0] = 0
    // v[0] + ... v[n-1] = prefix[n] - prefix[0]
    // 원소의 합의 최대값이 21억이 넘는다. 250,000 * 8,000
    lld max_summation = 0;
    int cnt = 0;
    for (int i = 0; i + X <= N; i++) {
        lld summation = prefix[i + X] - prefix[i];
        if (max_summation < summation) {
            max_summation = summation;
            cnt = 1;
        }
        else if (max_summation == summation) {
            cnt++;
        }
    }
    if (max_summation == 0) {
        cout << "SAD";
    }
    else {
        cout << max_summation << '\n' << cnt;
    }
    

    return 0;
}