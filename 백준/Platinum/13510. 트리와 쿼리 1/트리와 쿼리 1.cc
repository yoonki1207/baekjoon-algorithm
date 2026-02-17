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
백준 13510
HLD + Segmentation
*/
int N, M;
vector<vector<pair<int, int>>> adj;
vector<int> sz, dep, par, top, in, out;
vector<vector<int>> g;
vector<pair<pair<int, int>, int>> edges;

struct Seg {
    int tree[1 << 18] = { 0 };
    int sz = 1 << 17;

    void update(int x, int v) {
        x |= sz; tree[x] += v;
        while (x >>= 1) {
            tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
        }
    }

    //lld init(int x) {
    //    //tree[x] = init(x << 1) + init(x << 1 | 1);
    //}

    lld query(int l, int r) {
        l |= sz; r |= sz;
        lld ret = 0;
        while (l <= r) {
            if (l & 1) ret = max(ret, (lld)tree[l++]);
            if (~r & 1) ret = max(ret, (lld)tree[r--]);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
}seg;

void update(int v, int w) {
    seg.update(in[v], w);
}

lld query(int a, int b) {
    lld ret = 0;
    while (top[a] ^ top[b]) { 
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        ret = max(ret, seg.query(in[st], in[a]));
        a = par[st];
    }
    if (dep[a] > dep[b]) swap(a, b);
    ret = max(ret, seg.query(in[a] + 1, in[b]));
    return ret;
}

int chk[101010];
void dfs(int v = 1) {
    chk[v] = 1;
    for (auto i : adj[v]) {
        if (chk[i.first]) continue;
        chk[i.first] = 1;
        g[v].push_back(i.first);
        dfs(i.first);
    }
}

void dfs1(int v = 1) {
    sz[v] = 1;
    for (auto& i : g[v]) {
        dep[i] = dep[v] + 1; par[i] = v;
        dfs1(i); sz[v] += sz[i];
        if (sz[i] > sz[g[v][0]]) swap(i, g[v][0]);
    }
}

int pv = 0;
void dfs2(int v = 1) {
    in[v] = ++pv;
    for (auto i : g[v]) {
        top[i] = i == g[v][0] ? top[v] : i;
        dfs2(i);
    }
    out[v] = pv;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);
    cin >> N;
    int u, v, w;
    adj = vector<vector<pair<int, int>>>(N + 1);
    // sz, dep, par, top, in, out
    sz = vector<int>(N + 1);
    dep = vector<int>(N + 1);
    par = vector<int>(N + 1);
    top = vector<int>(N + 1);
    in = vector<int>(N + 1);
    out = vector<int>(N + 1);
    edges = vector<pair<pair<int, int>, int>>(N - 1);
    g = vector<vector<int>>(N + 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v >> w;
        edges[i] = { {u, v}, w };
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    dfs();
    dfs1(); 
    dfs2();
    
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first.first, v = edges[i].first.second;
        int w = edges[i].second;
        if (dep[u] < dep[v]) swap(u, v);
        // u is child
        update(u, w);
    }
    cin >> M;
    int q, a, b;
    for (int i = 0; i < M; i++) {
        cin >> q >> a >> b;
        if (q == 1) {
            int u = edges[a - 1].first.first, v = edges[a - 1].first.second;
            int w = edges[a - 1].second;
            if (dep[u] < dep[v]) swap(u, v);
            // u is child
            int diff = b - w;
            update(u, diff);
            edges[a - 1].second = b;
        }
        else {
            cout << query(a, b) << '\n';
        }
    }
    return 0;
}
