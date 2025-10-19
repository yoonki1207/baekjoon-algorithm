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
#define INF 987654321
#define MAX_N 32001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG
#define MOD 1000000009

using namespace std;

int n;
lld arr[100001];
lld brr[100001];
/*
1+1+1
1+2
2+1
*/

void solveUp() {
    memset(arr, -1, sizeof(arr));
    arr[0] = arr[1] = 1;
    for(int i = 2; i <= 100000; i++) {
        arr[i] = 0;
        if(i-1 >= 0) arr[i] += arr[i-1];
        if(i-2 >= 0) arr[i] += arr[i-2];
        arr[i] %= MOD;
    }
}

void solveDown() {
    memset(brr, -1, sizeof(brr));
    brr[0] = brr[1] = 1;
    for(int i = 2; i <= 100000; i++) {
        brr[i] = 0;
        if(i-1 >= 0) brr[i] += brr[i-1];
        if(i-2 >= 0) brr[i] += brr[i-2];
        if(i-3 >= 0) brr[i] += brr[i-3];
        if(i-4 >= 0) brr[i] += brr[i-4];
        brr[i] %= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solveDown(); solveUp();
    int T;
    cin >> T;
    while(T-->0) {
        cin >> n;
        lld ans = arr[n] * brr[n];
        ans %= MOD;
        cout << ans << '\n';
    }
    
    return 0;
}