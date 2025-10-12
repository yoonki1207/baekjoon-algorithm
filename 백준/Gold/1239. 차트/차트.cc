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

int N;
vector<int> v;
vector<bool> visited;

int countLine() {
    int ret = 0;
    vector<int> tmp(v.size() + 1);
    // 10 40 10 40
    // 0 10 50 60 100
    for(int i = 0; i < v.size(); i++) {
        tmp[i+1] = tmp[i] + v[i];
    }
    for(int i = 0; i < tmp.size() / 2; i++) {
        if(tmp[i] >= 50) break;
        for(int j = 1; j < tmp.size(); j++) {
            if(50+tmp[i] == tmp[j]) {
                ret++;
                break;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    v = vector<int>(N);
    visited = vector<bool>(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    do {
        int res = countLine();
        ans = max(ans, res);
    } while(next_permutation(v.begin(), v.end()));
    cout << ans;
    return 0;
}

/*
10 40 50

0 10 50 100

50 10 40
0 50 60 100

*/