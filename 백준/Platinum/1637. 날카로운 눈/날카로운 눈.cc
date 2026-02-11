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
백준 1637

*/
typedef struct {
    lld A, B, C;
} Node;
int N;
vector<Node> v;

lld cntNumberof(lld start, lld end) {
    // A + kB <= C
    // k <= (C-A) / B
    // 1 7 4 > 1, 5 ; 6/4 = 1.5
    // A + kB < start
    lld ret = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].A > end || v[i].C < start) continue;
        lld k = (min(end, v[i].C) - v[i].A) / v[i].B + 1;
        if(v[i].A <= start - 1) {
            lld o = ((start - 1) - v[i].A) / v[i].B + 1;
            k -= o;
        }
        ret += k;
    }
    return ret;
}

lld binsearch(lld start, lld end) {
    if(start == end) return start;
    if(start > end) return 0;
    lld mid = (start + end) / 2;
    lld left = cntNumberof(start, mid);
    lld right = cntNumberof(mid + 1, end);
    // cout << "Mid: " << mid << endl;
    // cout << "Binsearch: " << start << ' ' << end << ' ' << left << ' ' << right << endl;
    if(left % 2 == 1) {
        return binsearch(start, mid);
    } else if(right % 2 == 1) {
        return binsearch(mid + 1, end);
    } else {
        // nothing
        return -1;
    }
}


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    lld A, B, C;
    v = vector<Node>(N);
    for(int i = 0; i < N; i++) {
        cin >> A >> C >> B;
        v[i] = {A, B, C};
    }
    lld ans = binsearch(1, INT32_MAX);
    if(ans < 0) {
        cout << "NOTHING\n";
    } else {
        lld cnt = cntNumberof(ans, ans);
        cout << ans << ' ' << cnt << '\n';
    }
    return 0;
}
