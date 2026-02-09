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
백준 

*/
constexpr int MAX_N = 10001;
int T;
vector<int> cache;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    cache = vector<int>(MAX_N);
    cache[0] = 1;
    for(int i = 1; i <= 3; i++) {
        for(int j = i; j < MAX_N; j++) {
            cache[j] += cache[j - i];
        }
    }
    int x;
    while(T-->0) {
        cin >> x;
        cout << cache[x]<< '\n';
    }
    return 0;
}