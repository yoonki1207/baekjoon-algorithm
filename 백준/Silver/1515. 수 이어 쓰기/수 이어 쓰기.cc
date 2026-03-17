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
#include <random>
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

inline bool isConsist(int n, int k) {
    while(n) {
        if(n%10 == k) {
            return true;
        }
        n /= 10;
    }
    return false;
}

int jump(int n, const string& s, int index) {
    string p = to_string(n);
    int j = 0;
    int i = index;
    while(i < s.size() && j < p.size()) {
        if(p[j] == s[i]) {
            j++;
            i++;
        } else {
            j++;
        }
    }
    return i - index;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    int n = 0;
    for(int i = 0; i < s.size(); ++i) {
        char c = s[i] - '0';
        while(true) {
            ++n;
            if(int k = jump(n, s, i)) {
                // cout << "jump: " << k << endl;
                i += k-1;
                break;
            } else if(isConsist(n, c)) {
                break;
            }
        }
    }
    cout << n << endl;
    return 0;
}

// 9 * 3000 = 9560