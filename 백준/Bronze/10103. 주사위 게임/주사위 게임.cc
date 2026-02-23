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
int N;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int a, b;
    int q = 100, w = 100;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        if(a > b) {
            w -= a;
        } else if(a < b) {
            q -= b;
        }
    }
    cout << q << '\n' << w;
    return 0;
}
