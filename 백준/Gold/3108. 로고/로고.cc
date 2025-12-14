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