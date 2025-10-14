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

using namespace std;

int N; // 50
string x; // len <= 12
lld arr[255];
bool nonzero[255];
bool assigned[255];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x;
        size_t len = x.size();
        nonzero[(int)x[0]] = true;
        for(int j = 0; j < len; j++) {
            arr[(int)x[j]] += pow(10, len-j-1);
        }
    }
    
    vector<pair<lld, char>> v;
    for(char c = 'A'; c <= 'J'; c++) {
        if(arr[(int)c] == 0) continue;
        v.push_back({arr[(int)c], c});
    }
    sort(v.begin(), v.end(), greater<pair<lld, char>>());
    while(true) {
        if(v.size() == 10 && nonzero[v[9].second] == true) {
            prev_permutation(v.begin(), v.end());
        } else {
            break;
        }
    }
    lld ans = 0;
    lld k = 9;
    for(int i = 0; i < v.size(); i++) {
        ans += v[i].first * k;
        --k;
    }
    cout << ans << endl;
    return 0;
}

/*
ABC
BCA
C + A + B*10 + C*10 + A*100 + B*100
A*(100+1) + B*(100+10) + C*(10+1)
B > A > C

*/