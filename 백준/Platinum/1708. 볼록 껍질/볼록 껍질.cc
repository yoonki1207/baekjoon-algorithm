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
백준 1708
ccw

*/
constexpr int MAX_X = 40001;
int N;
vector<pair<pdd, pii>> coordinates;

inline double getDistace(lld x1, lld y1, lld x2, lld y2) {
    return sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
}

inline double getTheta(lld x1, lld y1, lld x2, lld y2) {
    return atan2(y2 - y1, x2 - x1);
}

// 0: straight, 1: rc, -1: c
double getCCW(lld x1, lld y1, lld x2, lld y2, lld x3, lld y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    coordinates = vector<pair<pdd, pii>>(N);
    int x, y;
    int sx = MAX_X;
    int sy = MAX_X;
    int index = -1;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        if(y < sy) {
            sy = y;
            sx = x;
            index = i;
        } else if(y == sy) {
            if(x < sx) {
                sx = x;
                index = i;
            }
        }
        coordinates[i] = {{0, 0}, {x, y}};
    }
    // calc theta
    swap(coordinates[0], coordinates[index]);
    for(int i = 1; i < N; i++) {
        x = coordinates[i].second.first;
        y = coordinates[i].second.second;
        coordinates[i].first = {getTheta(sx, sy, x, y), getDistace(sx, sy, x, y)};
    }
    // sort by theta
    // sort(coordinates.begin() + 1, coordinates.end());
    auto pivot = coordinates[0].second;
    sort(coordinates.begin() + 1, coordinates.end(),
        [&](const auto& A, const auto& B){
            auto a = A.second;
            auto b = B.second;
            lld c = (lld)(a.first - pivot.first) * (b.second - pivot.second)
                - (lld)(a.second - pivot.second) * (b.first - pivot.first);
            if(c != 0) return c > 0; // 반시계 먼저
            // 같은 방향이면 pivot에서 가까운 순
            lld da = (lld)(a.first - pivot.first)*(a.first - pivot.first)
                + (lld)(a.second - pivot.second)*(a.second - pivot.second);
            lld db = (lld)(b.first - pivot.first)*(b.first - pivot.first)
                + (lld)(b.second - pivot.second)*(b.second - pivot.second);
            return da < db;
        });

    vector<int> v;
    v.push_back(0);
    for(int i = 1; i < N; i++) {
        // before push, check clockwise
        while(v.size() >= 2) {
            int a = v[v.size()-2];
            int b = v.back();
            int x1 = coordinates[a].second.first;
            int y1 = coordinates[a].second.second;
            int x2 = coordinates[b].second.first;
            int y2 = coordinates[b].second.second;
            int x3 = coordinates[i].second.first;
            int y3 = coordinates[i].second.second;
            double ccw = getCCW(x1, y1, x2, y2, x3, y3);
            if(ccw <= 0) { // if clockwise or straight
                v.pop_back();
            } else {
                break;
            }
        }
        v.push_back(i);
    }
    cout << v.size() << endl;
    return 0;
}