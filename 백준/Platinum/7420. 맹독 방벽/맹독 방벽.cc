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
백준 7420
*/
int N, L;
vector<pii> coords;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

lld getDistanceDouble(int x1, int y1, int x2, int y2) {
    return (x2-x1) * (lld)(x2-x1) + (y2-y1) * (lld)(y2-y1);
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L;
    coords = vector<pii>(N);
    cin >> coords[0].first >> coords[0].second;
    int minx = coords[0].first, miny = coords[0].second, minidx = 0;
    for(int i = 1; i < N; i++) {
        cin >> coords[i].first >> coords[i].second;
        if(coords[i].second < miny) {
            minx = coords[i].first;
            miny = coords[i].second;
            minidx = i;
        } else if(coords[i].second == miny && coords[i].first < minx) {
            minx = coords[i].first;
            minidx = i;
        }
    }
    swap(coords[minidx], coords[0]);
    sort(coords.begin() + 1, coords.end(), [&](const pii& a, const pii& b) {
        int c = ccw(minx, miny, a.first, a.second, b.first, b.second);
        if(c == 0) {
            return getDistanceDouble(minx, miny, a.first, a.second) < getDistanceDouble(minx, miny, b.first, b.second);
        }
        return c > 0;
    });
    vector<int> v;
    v.push_back(0);
    for(int i = 1; i < N; i++) {
        if(v.size() >= 2) {
            while(v.size() >= 2) {
                int x1 = coords[v[v.size()-2]].first;
                int y1 = coords[v[v.size()-2]].second;
                int x2 = coords[v.back()].first;
                int y2 = coords[v.back()].second;
                int x3 = coords[i].first;
                int y3 = coords[i].second;
                int c = ccw(x1, y1, x2, y2, x3, y3);
                if(c <= 0) {
                    v.pop_back();
                } else {
                    break;
                }
            }
        }
        v.push_back(i);
    }

    double len = 0;
    for(int i = 1; i < v.size(); i++) {
        pii a = coords[v[i-1]];
        pii b = coords[v[i]];
        len += sqrt(getDistanceDouble(a.first, a.second, b.first, b.second));
    }
    len += sqrt(getDistanceDouble(coords[v[0]].first, coords[v[0]].second, coords[v.back()].first, coords[v.back()].second));
    len += L*2*M_PI;
    cout << (int)round(len) << endl;
    return 0;
}