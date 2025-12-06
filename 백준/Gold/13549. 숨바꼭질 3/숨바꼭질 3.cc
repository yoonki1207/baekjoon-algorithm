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
#define MOD 1000000009

using namespace std;

/*

*/
constexpr int MAX_N = 200'000;
int N, K;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(MAX_N+1);
    pq.push({0, N});
    visited[N] = true;
    while(!pq.empty()) {
        int cnt = pq.top().first;
        int pos = pq.top().second;
        pq.pop();
        // cout << cnt << endl;
        if(pos == K) {
            cout << cnt;
            break;
        }

        if(pos*2 <= MAX_N && !visited[pos*2]) {
            visited[pos*2] = true;
            pq.push({cnt, pos*2});
        }
        if(pos + 1 <= MAX_N && !visited[pos+1]) {
            visited[pos+1] = true;
            pq.push({cnt + 1, pos+1});
        }
        if(pos - 1 >= 0 && !visited[pos-1]) {
            visited[pos-1] = true;
            pq.push({cnt + 1, pos-1});
        }
        
    }

    return 0;
}

// 0 1 2 3 4 5 6 7
