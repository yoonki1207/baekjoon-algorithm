#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[1025][1025];
long long BIT[1025][1025];

void update(int x, int y, int diff) {
    for (int i = x; i <= N; i += i & -i) { // 자신보다 큰 2의 제곱수
        for (int j = y; j <= N; j += j & -j) {
            BIT[i][j] += diff;
        }
    }
}

long long query(int x, int y) {
    long long sum = 0;
    for (int i = x; i > 0; i -= i & -i) { // 자신보다 작은 2의 제곱수
        for (int j = y; j > 0; j -= j & -j) {
            sum += BIT[i][j];
        }
    }
    return sum;
}

long long rangeQuery(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> arr[i][j];
            update(i, j, arr[i][j]);
        }
    }

    while(M--) {
        int w;
        cin >> w;
        if(w == 0) {  // update
            int x, y, c;
            cin >> x >> y >> c;
            int diff = c - arr[x][y];
            arr[x][y] = c;
            update(x, y, diff);
        } else {      // query
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << rangeQuery(x1, y1, x2, y2) << "\n";
        }
    }

    return 0;
}