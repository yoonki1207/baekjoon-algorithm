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

constexpr int MAX_N = 10000;
constexpr int MAX_M = 1'000'000'001;
int N, M;
vector<int> v;

/* 각 예산이 upper_limit일 때 편성이 가능한가 */
bool isPossible(int upper_limit) {
    int summation = 0;
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        if (*iter <= upper_limit) {
            summation += *iter;
        }
        else {
            summation += upper_limit;
        }
    }
    return summation <= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    /* input */
    cin >> N;
    v = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    cin >> M;
    
    // N *log(M)
    int left = 0, right = MAX_M;
    int upper_limit = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(mid)) {
            upper_limit = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    int ans = 0;
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        if (*iter > upper_limit) {
            *iter = upper_limit;
        }
        ans = max(ans, *iter);
    }
    cout << ans;
    return 0;
}