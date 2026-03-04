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
백준 
*/



int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int A, B, N;
    cin >> A >> B;
    cin >> N;
    vector<int> bookmarks(N);
    for(int i = 0; i < N; i++) {
        cin >> bookmarks[i];
    }
    int ans = INF;
    for(int x: bookmarks) {
        ans = min(ans, abs(x-B) + 1);
    }
    ans = min(ans, abs(A-B));
    cout << ans;

    return 0;
}