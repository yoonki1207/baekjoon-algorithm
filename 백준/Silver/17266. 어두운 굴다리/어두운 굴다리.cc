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

/*

*/
int N, M;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> M;
    int gap = 0, x, prev_x;
    cin >> x;
    prev_x = x;
    gap = x;
    for(int i = 1; i < M; i++) {
        cin >> x;
        gap = max(gap, (x - prev_x+1)/2);
        prev_x = x;
    }
    gap = max(gap, N - x);
    cout << gap;
    return 0;
}

// 0 1 2 3 4 5 6 7
