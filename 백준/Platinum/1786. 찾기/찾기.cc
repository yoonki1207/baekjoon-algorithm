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
백준 1786

*/

vector<int> getPi(const string& p) {
    int m = p.size(), j = 0;
    vector<int> pi(m);
    for(int i = 1; i < m; i++) {
        while(j > 0 && p[i] != p[j]) j = pi[j - 1];
        if(p[i] == p[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

vector<int> kmp(const string& s, const string& p) {
    int n = s.size();
    int m = p.size();
    int j = 0;
    vector<int> pi = getPi(p);
    vector<int> ret;
    for(int i = 0; i < n; i++) {
        while(j > 0 && s[i] != p[j]) j = pi[j - 1];
        if(s[i] == p[j]) {
            if(j == m-1) {
                ret.push_back(i - m + 1);
                j = pi[j];
            } else {
                ++j;
            }
        }
    }
    return ret;
}


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string T, P;
    getline(cin, T);
    getline(cin, P);

    vector<int> v = kmp(T, P);
    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] + 1 << ' ';
    }
    return 0;
}