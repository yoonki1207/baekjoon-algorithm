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
백준 12781
*/

// pos: counter-clock wise / neg: clockwise / 0: line
int ccw(lld x1, lld y1, lld x2, lld y2, lld x3, lld y3) {
    lld result = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if(result > 0) return 1;
    else if (result < 0) return -1;
    return 0;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int c1 = ccw(x1, y1, x2, y2, x3, y3);
    int c2 = ccw(x1, y1, x2, y2, x4, y4);
    int c3 = ccw(x3, y3, x4, y4, x1, y1);
    int c4 = ccw(x3, y3, x4, y4, x2, y2);
    if(c1 * c2 < 0 && c3 * c4 < 0) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}