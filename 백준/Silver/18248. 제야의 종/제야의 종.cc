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

int N, M;

bool visited[1001];
int visited_size;

bool customCompare(const vector<int>& a, const vector<int>& b) {
    return a.size() < b.size();
}

bool solve(vector<int>& v) {
    int cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        if(visited[v[i]] == true) cnt++;
        visited[v[i]] = true;
    }
    return cnt == visited_size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    vector<vector<int>> v(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int x; cin >> x;
            if(x == 1) {
                v[i].push_back(j);
            }
        }
    }
    sort(v.begin(), v.end(), customCompare);
    for(int i = 0; i < v.size(); i++) {
        bool res = solve(v[i]);
        if(res == false) {
            cout << "NO\n";
            return 0;
        }
        visited_size = v[i].size();
    }
    cout << "YES\n";
    return 0;
}