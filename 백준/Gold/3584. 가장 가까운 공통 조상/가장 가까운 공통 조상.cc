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
백준 22233

*/
int T, N;
vector<int> nodes;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    int p, c;
    while(T-->0) {
        cin >> N;
        nodes = vector<int>(N + 1);
        for(int i = 0; i < N - 1; i++) {
            cin >> p >> c;
            nodes[c] = p;
        }
        int node1, node2;
        cin >> node1 >> node2;
        vector<int> v1, v2;
        while(true) {
            v1.push_back(node1);
            node1 = nodes[node1];
            if(node1 == 0) break;
        }
        while(true) {
            v2.push_back(node2);
            node2 = nodes[node2];
            if(node2 == 0) break;
        }
        int parent = 0;
        while(!v1.empty() && !v2.empty()) {
            if(v1.back() == v2.back()) {
                parent = v1.back();
                v1.pop_back();
                v2.pop_back();
            } else break;
        }
        cout << parent << '\n';
    }
    return 0;
}
