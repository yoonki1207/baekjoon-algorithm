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
백준 10266
하나의 바늘을 고정하고 모든 바늘에 대해서 탐색하는 경우
MAX_N = 200'000
N*N = 시간초과
바늘은 절대값이니, 상대값으로 판단할 수 있는 '각도'로 판별할 것.
90도 + 270도
270도 + 90도

공통 수열과 비슷한 문제이다.
혹은 문자열 찾기 알고리즘과 같다.
a b c d e
d e a b c
가 같음을 판별하라
a b c d e
d e a b c d e a b c

a a a b a
b a a a a b a a a a 

Angle에 대해서 KMP를 수행하라

*/
constexpr int MAX_ANGLE = 360'000;
int N;
vector<int> a, b;
vector<int> angle_a, angle_b;
// vector<int> p;


vector<int> getPi(const vector<int>& v) {
    int m = v.size();
    int j = 0;
    vector<int> pi(m, 0);
    for(int i = 1; i < m; i++) {
        while(j > 0 && v[i] != v[j]) {
            j = pi[j-1];
        }
        if(v[i] == v[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

vector<int> kmp(const vector<int>& s, const vector<int>& p) {
    vector<int> ans;
    vector<int> pi = getPi(p);
    int n = s.size();
    int m = p.size();
    int j = 0;
    for(int i = 1; i < n; i++) {
        while(j > 0 && s[i] != p[j]) {
            j = pi[j-1];
        }
        if(s[i] == p[j]) {
            if(j == m-1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            } else {
                ++j;
            }
        }
    }
    return ans;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    a = vector<int>(N);
    b = vector<int>(N);
    angle_a = vector<int>(N);
    angle_b = vector<int>(N * 2);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int s = 0;
    for(int i = 1; i < N; i++) {
        int angle = a[i] - a[i-1];
        angle_a[i-1] = angle;
        s += angle;
    }
    angle_a[N-1] = MAX_ANGLE - s;
    s = 0;

    for(int i = 0; i < N; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for(int i = 1; i < N; i++) {
        int angle = b[i] - b[i-1];
        angle_b[i-1] = angle;
        s += angle;
    }
    angle_b[N-1] = MAX_ANGLE - s;
    for(int i = 0; i < N; i++) {
        angle_b[N + i] = angle_b[i];
    }
    // kmp
    vector<int> ans = kmp(angle_b, angle_a);
    if(ans.size() > 0) {
        cout << "possible";
    } else {
        cout << "impossible";
    }
    
    return 0;
}
