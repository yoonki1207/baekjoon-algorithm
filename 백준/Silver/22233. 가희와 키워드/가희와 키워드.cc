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
백준 22233

*/
int N, M;
set<string> keywords;

vector<string> split(string text, const char sep) {
    vector<string> ret;
    size_t pos = 0;
    size_t find_pos = 0;
    while((find_pos = text.find(sep, pos)) != string::npos) {
        ret.push_back(text.substr(pos, find_pos - pos));
        pos = find_pos + 1;
    }
    ret.push_back(text.substr(pos));
    return ret;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    string s;
    for(int i = 0; i < N; i++) {
        cin >> s;
        keywords.insert(s);
    }
    for(int i = 0; i < M; i++) {
        cin >> s;
        vector<string> res = split(s, ',');
        for(string k: res) {
            keywords.erase(k);
        }
        cout << keywords.size() << '\n';
    }
    
    return 0;
}