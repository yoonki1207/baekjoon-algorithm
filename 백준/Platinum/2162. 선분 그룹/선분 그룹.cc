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
백준 11438 LCA 2
이분탐색 LCA
*/
int N;
vector<pair<pii, pii>> v;
vector<int> parent;
vector<int> group_cnt;

int orient(lld ax, lld ay, lld bx, lld by, lld cx, lld cy) {
    lld v = (bx - ax) * (cy - ay) - (by - ay) * (cx-ax);
    if(v > 0) return 1;
    if(v < 0) return -1;
    return 0;
}

int onSegment(int ax, int ay, int bx, int by, int px, int py) {
    return (min(ax, bx) <= px && px <= max(ax, bx)) &&
        (min(ay, by) <= py && py <= max(ay, by));
}

int segmentsIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int o1 = orient(x1, y1, x2, y2, x3, y3);
    int o2 = orient(x1, y1, x2, y2, x4, y4);
    int o3 = orient(x3, y3, x4, y4, x1, y1);
    int o4 = orient(x3, y3, x4, y4, x2, y2);
    if(o1*o2 < 0 && o3*o4 < 0) return true; // 완전 교차
    if(o1 == 0 && onSegment(x1, y1, x2, y2, x3, y3)) return true;
    if(o2 == 0 && onSegment(x1, y1, x2, y2, x4, y4)) return true;
    if(o3 == 0 && onSegment(x3, y3, x4, y4, x1, y1)) return true;
    if(o4 == 0 && onSegment(x3, y3, x4, y4, x2, y2)) return true;
    return false;
}

int getParent(int a) {
    if(parent[a] != a) return parent[a] = getParent(parent[a]);
    return a;
}

void unionParent(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);
    if(pa < pb) parent[pb] = pa;
    else if(pa > pb) parent[pa] = pb;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int x1, y1, x2, y2;
    v = vector<pair<pii, pii>>(N);
    parent = vector<int>(N);
    group_cnt = vector<int>(N);
    for(int i = 0; i < parent.size(); i++) parent[i] = i;
    for(int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        v[i] = {{x1, y1}, {x2, y2}};
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(segmentsIntersect(
                v[i].first.first, v[i].first.second,
                v[i].second.first, v[i].second.second,
                v[j].first.first, v[j].first.second,
                v[j].second.first, v[j].second.second
            )) {
                unionParent(i, j);
                int p = getParent(i);
            }
        }
    }
    set<int> s;
    for(int i = 0; i < N; i++) {
        int p = getParent(i);
        group_cnt[p]++;
        s.insert(p);
    }
    int ans = 1;
    for(int i = 0; i < N; i++) {
        if(group_cnt[i] > 1) {
            ans = max(ans, group_cnt[i]);
        }
    }
    if(N == 1) {
        cout << 1 << '\n' << 1 << endl;
    } else {
        cout << s.size() << '\n' << ans << endl;    
    }

    
    return 0;
}
