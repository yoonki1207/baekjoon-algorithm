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
*/


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) cnt++;
    }
    cout << cnt;
    
    return 0;
}
