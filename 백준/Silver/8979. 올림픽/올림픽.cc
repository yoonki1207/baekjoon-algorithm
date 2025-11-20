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
#define MAX_N 32001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG
#define MOD 1000000009

using namespace std;

int N, K;

struct Node {
    int gold;
    int silver;
    int bronze;
    int num;
};

bool isSame(struct Node a, struct Node b) {
    return a.gold == b.gold && a.silver == b.silver && a.bronze == b.bronze;
}

bool customCompare(struct Node a, struct Node b) {
    if(a.gold == b.gold) {
        if(a.silver == b.silver) {
            return a.bronze > b.bronze;
        }
        return a.silver > b.silver;
    }
    return a.gold > b.gold;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> K;
    vector<struct Node> v;
    for(int i = 1; i <= N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({b, c, d, a});
    }
    sort(v.begin(), v.end(), customCompare);
    vector<int> k;
    int before = 1;
    for(int i = 0; i < v.size(); i++) {
        if(i > 0 && isSame(v[i-1], v[i])) {
            k.push_back(before);
        } else {
            before = i+1;
            k.push_back(before);
        }
    }
    for(int i = 0; i < v.size(); i++) {
        if(v[i].num == K) {
            cout << k[i];
            break;
        }
    }
    return 0;
}
