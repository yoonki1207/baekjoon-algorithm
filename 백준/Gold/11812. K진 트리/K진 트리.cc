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

/*
백준 11812 K진 트리 19:45

mathmetics

둘 중 깊이가 더 깊은 노드의 조상 노드와 남은 노드를 비교하며 올라가기.

노드의 depth = sigma()
*/
constexpr int MAX_DEPTH = 51; // N이 10^15, K가 2일 떄 최대 깊이 50
lld N, K, Q;
lld x, y;

lld getParent(lld node) {
    return (node - 2) / K + 1;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K >> Q;
    while(Q-->0) {
        cin >> x >> y;
        lld len = 0;
        if(K == 1) {
            cout << abs(y-x) << '\n';
            continue;
        }
        while(x != y) {
            if(x > y) {
                x = getParent(x);
            } else {
                y = getParent(y);
            }
            len++;
        }
        cout << len << '\n';
    }

    return 0;
}

/*
1000000000000000
1000
1 2

1000000000000000 2 1
1000000000000000 1
*/