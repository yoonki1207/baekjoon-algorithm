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
백준 9240

*/
constexpr int MAX_N = 100'001;
int N;
vector<pair<int, int>> coords;

inline lld dist2(int x1 ,int y1, int x2, int y2) {
    return (x2-x1) * (x2-x1) + (y2-y1)*(y2-y1);
}
inline lld dist2(pair<int, int> a, pair<int, int> b) {
    return dist2(a.first, a.second, b.first, b.second);
}

// positive: counter-clockwise, negative: clockwise, equal: line
inline int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}
inline int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return ccw(a.first, a.second, b.first, b.second, c.first, c.second);
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int x, y;
    coords = vector<pair<int, int>>(N);
    cin >> x >> y;
    coords[0] = {x, y};
    pair<int, int> current_coord = coords[0];
    int idx = 0;
    for(int i = 1; i < N; i++) {
        cin >> x >> y;
        coords[i] = {x, y};
        if(current_coord.second > coords[i].second) {
            current_coord = coords[i];
            idx = i;
        } else if(current_coord.second == coords[i].second && current_coord.first > coords[i].first) {
            current_coord = coords[i];
            idx = i;
        }
    }
    swap(coords[0], coords[idx]);
    sort(coords.begin() + 1, coords.end(), [current_coord](const pii& a, const pii& b) {
        int c = ccw(current_coord, a, b);
        if (c == 0) {
            return dist2(current_coord, a) < dist2(current_coord, b);
        }
        return c > 0; 
    });
    vector<pair<int, int>> stk;
    stk.push_back(current_coord);
    for(int i = 1; i < N; i++) {
        pair<int, int> next_coord = coords[i];
        while(stk.size() >= 2) {
            pair<int, int> a = stk[stk.size() - 2];
            pair<int, int> b = stk.back();
            int res = ccw(a, b, next_coord);
            if(res <= 0){
                stk.pop_back();
            } else {
                break;
            }
        }
        stk.push_back(next_coord);
    }
    lld dist = 0;
    for(int i = 0; i < stk.size(); i++) {
        for(int j = i + 1; j < stk.size(); j++) {
            lld d = dist2(stk[i], stk[j]);
            dist = max(dist, d);
        }
    }
    cout << fixed; cout.precision(8);
    cout << sqrt(dist) << endl;
    
    return 0;
}
