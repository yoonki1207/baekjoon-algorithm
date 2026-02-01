#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#include <set>
#define INF 987654321
#define lld long long
#define pii pair<int, int>

using namespace std;
/*
백준 2887
약간그 뭐냐 최소신장트리 느낌인데
간선의 모든 경우의 수는 필요 없으니까 최적화를 조금 하자면
각 축에 대해서만 생각해서 정렬한 후, 그 차이를 저장한다.
a, b의 간선 길이 c. 이런식으로
이걸 x, y, z 모든 축에 대해서 수행한다.
그런 후에 priority queue를 이용한다. 간선이 작은 것이 우선순위다.
이에 대해서 최소신장트리를 결정하라.
*/

class Point {
public:
    int n;
    int x, y, z;
    Point(int x, int y, int z) : x(x), y(y), z(z), n(0) {}
    Point() { Point(0, 0, 0); }
};
bool xsort(const Point& a, const Point& b) {
    return a.x < b.x;
}
bool ysort(const Point& a, const Point& b) {
    return a.y < b.y;
}
bool zsort(const Point& a, const Point& b) {
    return a.z < b.z;
}
constexpr int MAX_N = 100000;
int N;
vector<Point> points;
vector<int> parent;

int getParent(int x) {
    if (x != parent[x]) return parent[x] = getParent(parent[x]);
    return x;
}

void unionParent(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);
    if (pa < pb) parent[pb] = pa;
    if (pa > pb) parent[pa] = pb;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    points = vector<Point>(N);
    parent = vector<int>(N);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        cin >> points[i].x >> points[i].y >> points[i].z;
        points[i].n = i;
    }
    priority_queue < 
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    sort(points.begin(), points.end(), xsort);
    for (int i = 1; i < points.size(); i++) {
        Point& prev = points[i - 1];
        Point& next = points[i];
        int gap = abs(next.x - prev.x);
        pq.push({ gap, {next.n, prev.n} });
    }

    sort(points.begin(), points.end(), ysort);
    for (int i = 1; i < points.size(); i++) {
        Point& prev = points[i - 1];
        Point& next = points[i];
        int gap = abs(next.y - prev.y);
        pq.push({ gap, {next.n, prev.n} });
    }

    sort(points.begin(), points.end(), zsort);
    for (int i = 1; i < points.size(); i++) {
        Point& prev = points[i - 1];
        Point& next = points[i];
        int gap = abs(next.z - prev.z);
        pq.push({ gap, {next.n, prev.n} });
    }

    int cnt = 0;
    lld dist = 0;
    while (!pq.empty() && cnt < N-1) {
        int d = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        if (getParent(a) != getParent(b)) {
            dist += (lld)d;
            unionParent(a, b);
            cnt++;
        }
    }
    cout << dist;
    
    return 0;
}
