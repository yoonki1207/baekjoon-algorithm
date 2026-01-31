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
백준 9177
*/
constexpr int MAX_LEN = 201;
constexpr int MAX_N = 1001;
int N;
string a, b, c;

// 
vector<vector<bool>> visited;

bool solve(int index_a, int index_b, int index_c) {
    if(index_c == c.size()) {
        return true;
    }
    if(visited[index_a][index_b]) {
        return false;
    }
    visited[index_a][index_b] = true;
    if(a[index_a] == c[index_c] && b[index_b] == c[index_c]) {
        return solve(index_a + 1, index_b, index_c + 1) || solve(index_a, index_b + 1, index_c + 1);
    } else if(a[index_a] == c[index_c]) {
        return solve(index_a + 1, index_b, index_c + 1);
    } else if(b[index_b] == c[index_c]) {
        return solve(index_a, index_b + 1, index_c + 1);
    } else {
        return false;
    }
}


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        visited = vector<vector<bool>>(MAX_LEN, vector<bool>(MAX_LEN, false));
        cin >> a >> b >> c;
        a.push_back('.');
        b.push_back('.');
        bool ans = solve(0, 0, 0);
        if(ans) {
            cout << "Data set " << i + 1 << ": yes\n";
        } else {
            cout << "Data set " << i + 1 << ": no\n";
        }
    }
    return 0;
}