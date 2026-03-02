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
백준 
*/

int T(int x) {
    return x*(x+1)/2;
}

int W(int x) {
    lld ret = 0;
    for(int k = 1; k <= x; k++) {
        ret += k * T(k + 1);
    }
    return ret;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    int x;
    for(int i = 0; i < T; i++) {
        cin >> x;
        cout << W(x) << '\n';
    }
    return 0;
}