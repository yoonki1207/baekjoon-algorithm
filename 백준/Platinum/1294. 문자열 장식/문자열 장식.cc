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


struct comp {
    bool operator()(const string& s1, const string& s2) {
        return s1 + s2 > s2 + s1;
    }
};

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    priority_queue<string, vector<string>, comp> pq;
    string s; 
    while(T-->0) {
        cin >> s;
        pq.push(s);
    }
    string ret;
    while(!pq.empty()) {
        string top = pq.top();
        pq.pop();
        ret.push_back(top[0]);
        if(top.size() > 1) pq.push(top.substr(1));
    }
    cout << ret << endl;
    return 0;
}