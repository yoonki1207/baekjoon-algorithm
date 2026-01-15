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
// #define MOD 1000000009

using namespace std;
constexpr lld MOD = 1'000'000'007;
constexpr int MAX_N = 1000000;
int N, M, K;
vector<lld> v;
int tree[MAX_N * 4];

/*
백준 11505

*/

int init(int start, int end, int node) {
    if(start == end) return tree[node] = v[start];
    int mid = (start + end) / 2;
    lld left = init(start, mid, node*2);
    lld right = init(mid + 1, end, node*2+1);
    return tree[node] = (left * right) % MOD;
}

void update(int start, int end, int node, int pos, int val) {
    if(start > pos || end < pos) return;
    int mid = (start + end) / 2;
    if(start == end) {
        tree[node] = val;
        return;
    }
    update(start, mid, node * 2, pos, val);
    update(mid + 1, end, node * 2 + 1, pos, val);
    tree[node] = ((lld)tree[node * 2] * (lld)tree[node * 2 + 1]) % MOD;
}

lld query(int start, int end, int node, int left, int right) {
    if(left <= start && end <= right) return (lld)tree[node];
    if(end < left || right < start) return 1ll;
    int mid = (start + end) / 2;
    return (query(start, mid, node * 2, left, right) * query(mid + 1, end, node * 2 + 1, left, right)) % MOD;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    v = vector<lld>(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    init(0, N - 1, 1);
    int a, b, c;
    for(int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            update(0, N-1, 1, b - 1, c);
            v[b-1] = c;
        } else {
            lld res = query(0, N-1, 1, b-1, c-1);
            cout << res << '\n';
        }
    }
    return 0;
}
