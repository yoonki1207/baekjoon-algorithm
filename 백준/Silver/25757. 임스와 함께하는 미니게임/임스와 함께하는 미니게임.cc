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
#define MOD 1000000009

using namespace std;

set<string> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    char g;
    cin >> N >> g;
    string x;
    for(int i = 0; i < N; i++) {
        cin >> x;
        s.insert(x);
    }
    int ans = 0;
    if(g == 'Y') {
        ans = s.size();
    } else if (g == 'F') {
        ans = s.size() / 2;
    } else {
        ans = s.size() / 3;
    }
    cout << ans << endl;

    return 0;
}