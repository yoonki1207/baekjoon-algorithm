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
int N, M, L, K;

/*
백준 14685

*/


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> L >> K;
    vector<pair<int, int>> stars(K);
    for(int i = 0; i < K; i++) {
        cin >> stars[i].first >> stars[i].second;
    }
    int c = 0;
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < K; j++) {
            int left = stars[i].first;
            int bottom = stars[j].second;
            int cnt = 0;
            for(int s = 0; s < K; s++) {
                int x = stars[s].first;
                int y = stars[s].second;
                if(left <= x && x <= left + L && bottom <= y && y <= bottom + L) cnt++;
            }
            c = max(c, cnt);
        }
    }
    cout << K - c;
    return 0;
}
