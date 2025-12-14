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


class Coord { 
public:
    int x;
    int y;
    Coord(): x(0), y(0) {}
    Coord(int x, int y) : x(x), y(y) {}
    bool operator>(const Coord& o) {
        return pii{ x, y } > pii{ o.x, o.y };
    }
};
class Line {
public:
    Coord start;
    Coord end;
    Line() {}
    Line(Coord start, Coord end) : start(start), end(end) {}
    Line(int x1, int y1, int x2, int y2) {
        Line(Coord{ x1, y1 }, Coord{ x2, y2 });
    }
};
class Rect {
public:
    Coord start;
    Coord end;
    Rect() {}
    Rect(int x1, int y1, int x2, int y2) {
        start = Coord(x1, y1);
        end = Coord(x2, y2);
    }
    vector<Line> getLines() const;
};

vector<Line> Rect::getLines() const {
    vector<Line> ret(4);
    ret[0] = Line{ start.x, start.y, start.x, end.y };
    ret[1] = Line{ start.x, start.y, end.x, start.y };
    ret[2] = Line{ end.x, start.y, end.x, end.y };
    ret[3] = Line{ start.x, end.y, end.x, end.y };
    return ret;
};

/* Variables */
constexpr size_t MAX_N = 1001;
int arr[MAX_N];
int N;
vector<Rect> rectangles;

int getParent(int x) {
    if (arr[x] != x) return getParent(arr[x]);
    return x;
}

void unionParent(int x, int y) {
    int px = getParent(x);
    int py = getParent(y);
    if (px < py) arr[py] = px;
    else arr[px] = py;
}

int ccw(Coord a, Coord b, Coord c) {
    int s = a.x * b.y + b.x * c.y + c.x * a.y;
    s -= (a.y * b.x + b.y * c.x + c.y * a.x);
    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1;
}

bool isIntersect(Line a, Line b) {
    Coord p1 = a.start;
    Coord p2 = a.end;
    Coord p3 = b.start;
    Coord p4 = b.end;

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (p1p2 == 0 && p3p4 == 0) {
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);
        return !(p3 > p2) && !(p1 > p4);
    }
    return p1p2 <= 0 && p3p4 <= 0;
}

bool isCollision(const Rect a, const Rect& b) {
    if (b.end.y > a.end.y && a.end.x < b.end.x && a.start.y > b.start.y && b.start.x < a.start.x)
        return false;
    if (a.end.y > b.end.y && b.end.x < a.end.x && b.start.y > a.start.y && a.start.x < b.start.x)
        return false;
    if (b.start.y > a.end.y || b.start.x > a.end.x || a.start.y > b.end.y || b.end.x < a.start.x)
        return false;
    return true;

}


int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < MAX_N; i++) arr[i] = i;

    bool isPassZero = false;
    Rect zeroRect{ 0, 0, 0, 0 };

    cin >> N;
    int x1, y1, x2, y2;
    rectangles = vector<Rect>(N);
    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        rectangles[i] = Rect{ x1, y1, x2, y2 };
        if(isCollision(zeroRect, rectangles[i])) isPassZero = true;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (isCollision(rectangles[i], rectangles[j])) {
                unionParent(i, j);
            }
        }
    }
    set<int> s;
    for (int i = 0; i < N; i++) {
        s.insert(getParent(i));
    }
    int cnt_logo = s.size();
    cout << cnt_logo - (int)isPassZero;
    return 0;
}