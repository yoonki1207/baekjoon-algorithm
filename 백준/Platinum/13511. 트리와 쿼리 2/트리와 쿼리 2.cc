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
백준 13511
LCA Lowest Common Ancestor
*/
int N, Q;
int LOGN;
vector<vector<pair<lld, lld>>> Tree;
vector<lld> Depth;
vector<lld> Weight;
vector<vector<lld>> Up;

void init() {
    /* Initialize Depth and Weight*/
    int root = 1;

    queue<pair<lld, pair<lld, lld>>> q;
    vector<bool> visited(N + 1);
    q.push({ root, {0, 0} }); // node, depth, weight
    visited[root] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int depth = q.front().second.first;
        lld weight = q.front().second.second;
        q.pop();
        for (int i = 0; i < Tree[node].size(); i++) { // childrens of 'node'
            int next = Tree[node][i].first;
            lld next_weight = Tree[node][i].second;
            if (visited[next]) continue;
            visited[next] = true;
            Depth[next] = depth + 1;
            Weight[next] = weight + next_weight;
            Up[next][0] = node;
            q.push({ next, {Depth[next], Weight[next]} });
        }
    }
    /* Initialize Up as dp*/
    for (size_t k = 1; k < Up[0].size(); k++) {
        for (int x = 1; x <= N; x++) {
            Up[x][k] = Up[Up[x][k - 1]][k - 1]; // x의 2^k번째 조상은 x의 2^k-1 번째 조상의 2^k-1번째 조상과 같다.
        }
    }
}

lld last_u = 0, last_v = 0, last_ret = 0;
lld getLCANode(lld u, lld v) {
    if (Depth[u] < Depth[v]) {
        swap(u, v);
    }
    if (last_u == u && last_v == v) {
        return last_ret;
    }
    int diff = Depth[u] - Depth[v];
    for (int k = 0; k < LOGN; k++) {
        if (diff & (1 << k)) {
            u = Up[u][k];
        }
    }
    if (u == v) return u;
    for (int k = Up[0].size() - 1; k >= 0; --k) {
        if (Up[u][k] != Up[v][k]) {
            u = Up[u][k];
            v = Up[v][k];
        }
    }
    return last_ret = Up[u][0];
}

lld getWeight(lld u, lld v) {
    lld p = getLCANode(u, v);
    return Weight[u] - Weight[p]*2 + Weight[v];
}

lld getNthNode(lld u, lld v, lld nth) {
    lld p = getLCANode(u, v);
    int nodeCnt = Depth[u] - Depth[p] * 2 + Depth[v] + 1; // include u and v
    if (nth == 1) return u;
    if (nth == nodeCnt) return v;
    if (nth == Depth[u] - Depth[p] + 1) return p;
    if (nth < Depth[u] - Depth[p] + 1) {
        // u의 nth
        int diff = nth - 1;

        for (int k = 0; k < LOGN; k++) {
            if (diff & (1 << k)) {
                u = Up[u][k];
            }
        }
        return u;
    }
    else {
        int diff = nodeCnt - nth;

        for (int k = 0; k < LOGN; k++) {
            if (diff & (1 << k)) {
                v = Up[v][k];
            }
        }
        return v;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(NULL);
    cin >> N;
    lld a, b, c;
    Tree = vector<vector<pair<lld, lld>>>(N + 1);
    Depth = vector<lld>(N + 1);
    Weight = vector<lld>(N + 1);
    Up = vector<vector<lld>>(N + 1, vector<lld>(log2(N) + 2));
    LOGN = 1; while ((1 << LOGN) <= N) LOGN++;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        Tree[a].push_back({ b, c });
        Tree[b].push_back({ a, c });
    }
    init();
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> a;
        if (a == 1) {
            cin >> a >> b;
            cout << getWeight(a, b) << '\n';
        }
        else {
            cin >> a >> b >> c;
            cout << getNthNode(a, b, c) << '\n';
        }
    }
    return 0;
}
