#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
    int diff, sum;
    int nxt[4]; // 0:A 1:B 2:C 3:D
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    string cmd;
    cin >> cmd;

    vector<Node> nodes(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        nodes[i].x = x;
        nodes[i].y = y;
        nodes[i].diff = x - y;
        nodes[i].sum  = x + y;
        for (int d = 0; d < 4; d++) nodes[i].nxt[d] = -1;
    }

    // (diff, x)로 정렬해서 A/D 링크
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b){
        if (nodes[a].diff != nodes[b].diff) return nodes[a].diff < nodes[b].diff;
        return nodes[a].x < nodes[b].x;
    });

    for (int i = 0; i < N; ) {
        int j = i;
        while (j < N && nodes[ord[j]].diff == nodes[ord[i]].diff) j++;
        // ord[i..j-1] 같은 diff, x 오름차순
        for (int k = i; k < j; k++) {
            int id = ord[k];
            nodes[id].nxt[0] = (k+1 < j ? ord[k+1] : -1); // A
            nodes[id].nxt[3] = (k-1 >= i ? ord[k-1] : -1); // D
        }
        i = j;
    }

    // (sum, x)로 정렬해서 B/C 링크
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b){
        if (nodes[a].sum != nodes[b].sum) return nodes[a].sum < nodes[b].sum;
        return nodes[a].x < nodes[b].x;
    });

    for (int i = 0; i < N; ) {
        int j = i;
        while (j < N && nodes[ord[j]].sum == nodes[ord[i]].sum) j++;
        // ord[i..j-1] 같은 sum, x 오름차순
        for (int k = i; k < j; k++) {
            int id = ord[k];
            nodes[id].nxt[1] = (k+1 < j ? ord[k+1] : -1); // B
            nodes[id].nxt[2] = (k-1 >= i ? ord[k-1] : -1); // C
        }
        i = j;
    }

    auto removeNode = [&](int id) {
        int A = nodes[id].nxt[0];
        int B = nodes[id].nxt[1];
        int C = nodes[id].nxt[2];
        int D = nodes[id].nxt[3];

        if (D != -1) nodes[D].nxt[0] = A;
        if (A != -1) nodes[A].nxt[3] = D;
        if (B != -1) nodes[B].nxt[2] = C;
        if (C != -1) nodes[C].nxt[1] = B;
    };

    int DIR[128];
    DIR['A'] = 0; DIR['B'] = 1; DIR['C'] = 2; DIR['D'] = 3;

    int cur = 0;
    for (int i = 0; i < K; i++) {
        int d = DIR[(unsigned char)cmd[i]];
        int nx = nodes[cur].nxt[d];
        if (nx != -1) {
            int prev = cur;
            cur = nx;
            removeNode(prev);
        }
    }

    cout << nodes[cur].x << ' ' << nodes[cur].y << '\n';
    return 0;
}