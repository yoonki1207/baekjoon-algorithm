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
/*
백준 2357
*/
int N, M;

struct MaxSeg {
    int tree[1 << 18] = { 0 };
    int sz = 1 << 17;

    void update(int x, int v) {
        x |= sz; tree[x] += v;
        while (x >>= 1) {
            tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
        }
    }

    int query(int l, int r) {
        l |= sz; r |= sz;
        int ret = 0;
        while (l <= r) {
            if (l & 1) ret = max(ret, tree[l++]);
            if (~r & 1) ret = max(ret, tree[r--]);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
}maxseg;

struct MinSeg {
    int tree[1 << 18] = { 0 };
    int sz = 1 << 17;

    void update(int x, int v) {
        x |= sz; tree[x] = v;
        while (x >>= 1) {
            tree[x] = min(tree[x << 1], tree[x << 1 | 1]);
        }
    }

    int query(int l, int r) {
        l |= sz; r |= sz;
        int ret = INT32_MAX;
        while (l <= r) {
            if (l & 1) ret = min(ret, tree[l++]);
            if (~r & 1) ret = min(ret, tree[r--]);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
}minseg;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);
    cin >> N >> M;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        minseg.update(i, x);
        maxseg.update(i, x);
    }
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        --a; --b;
        int q = minseg.query(a, b);
        int w = maxseg.query(a, b);
        cout << q << ' ' << w << '\n';
    }
    return 0;
}
