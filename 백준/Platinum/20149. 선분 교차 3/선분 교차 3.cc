#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321
#define MAX_N 1000001
#define lld long long int
using namespace std;

lld x1, Y1, x2, y2, x3, y3, x4, y4;

lld dirCrossProduct(lld x1, lld Y1, lld x2, lld y2) {
	return x1*y2-x2*Y1;
}

pair<double, double> crossPoint(lld x1, lld Y1, lld x2, lld y2, lld x3, lld y3, lld x4, lld y4) {
	double x = (double)((x1*y2-Y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(Y1-y2)*(x3-x4));
	double y = (double)((x1*y2-Y1*x2)*(y3-y4)-(Y1-y2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(Y1-y2)*(x3-x4));
	return {x, y};
}

inline lld distanceSquare(lld x1, lld Y1, lld x2, lld y2) {
	return (x2-x1)*(x2-x1)+(y2-Y1)*(y2-Y1);
}

inline bool isSamePoint(lld x1, lld Y1, lld x2, lld y2, lld x3, lld y3, lld x4, lld y4) {
	return (x1 == x3 && Y1 == y3) || (x1 == x4 && Y1 == y4) || (x2 == x3 && y2 == y3) || (x2 == x4 && y2 == y4);
}

inline bool isInOneLine(lld x1, lld Y1, lld x2, lld y2, lld x3, lld y3, lld x4, lld y4) {
	lld a1 = dirCrossProduct(x2-x1, y2-Y1, x3-x1, y3-Y1);
	lld a2 = dirCrossProduct(x2-x1, y2-Y1, x4-x1, y4-Y1);
	lld b1 = dirCrossProduct(x4-x3, y4-y3, x2-x3, y2-y3);
	lld b2 = dirCrossProduct(x4-x3, y4-y3, x1-x3, Y1-y3);
	return a1 == 0 && a2 == 0 && b1 == 0 && b2 == 0;
}

inline lld min(lld a, lld b, lld c, lld d) {
	return min(a, min(b, min(c,d)));
}

inline lld max(lld a, lld b, lld c, lld d) {
	return max(a, max(b, max(c,d)));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> x1 >> Y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	
	lld a1 = dirCrossProduct(x2-x1, y2-Y1, x3-x1, y3-Y1);
	lld a2 = dirCrossProduct(x2-x1, y2-Y1, x4-x1, y4-Y1);
	lld b1 = dirCrossProduct(x4-x3, y4-y3, x2-x3, y2-y3);
	lld b2 = dirCrossProduct(x4-x3, y4-y3, x1-x3, Y1-y3);
	
	bool isCrossed = false;
	bool isOne = false;
	double u=INF, v=INF;
	// cout << a1 << ' '<< a2 << ' ' << b1 << ' ' << b2 << endl;
	a1 = a1 == 0 ? 0 : (a1 < 0 ? -1 : 1);
	a2 = a2 == 0 ? 0 : (a2 < 0 ? -1 : 1);
	b1 = b1 == 0 ? 0 : (b1 < 0 ? -1 : 1);
	b2 = b2 == 0 ? 0 : (b2 < 0 ? -1 : 1);
	if(isSamePoint(x1, Y1, x2, y2, x3, y3, x4, y4)) { // 끝 점이 같다.
		isCrossed = true;
		isOne = true;
		if(isInOneLine(x1, Y1, x2, y2, x3, y3, x4, y4)) {
			lld w = abs(x2-x1) + abs(x4-x3);
			lld h = abs(y2-Y1) + abs(y4-y3);
			// cout << "겹" << w*w+h*h << ' ' <<  distanceSquare(min(x1, x2, x3, x4), min(Y1, y2, y3, y4), max(x1, x2, x3, x4), max(Y1, y2, y3, y4))<< endl;
			if(w*w+h*h > distanceSquare(min(x1, x2, x3, x4), min(Y1, y2, y3, y4), max(x1, x2, x3, x4), max(Y1, y2, y3, y4))) { // 겹친다.
				isOne = false;
			}
		}
		if(x1 == x3 && Y1 == y3) {
			u = x1;
			v = Y1;
		} else if(x1 == x4 && Y1 == y4) {
			u = x1; v = Y1;
		} else if(x2 == x3 && y2 == y3) {
			u = x2; v = y2;
		} else {
			u = x2; v = y2;
		}
	} else if(a1*a2 < 0 && b1*b2 < 0) { // 완전히 교차한다.
		isCrossed = true;
		isOne = true;
		pair<double, double> c = crossPoint(x4, y4, x3, y3, x2, y2, x1, Y1);
		// cout << c.first << ' ' << c.second;
		u = c.first;
		v = c.second;
		// cout << "asd " << u << ' ' << v << endl;
		// TODO 교차점 구하기
	} else if(a1*a2 <= 0 && b1*b2 <= 0) { // 한 점에서 만나지만, 한 점이 다른 직선 위에 있다.
		isCrossed = true;
		if(isInOneLine(x1, Y1, x2, y2, x3, y3, x4, y4)) { // 일직선상
			lld w = abs(x2-x1) + abs(x4-x3);
			lld h = abs(y2-Y1) + abs(y4-y3);if(w*w+h*h > distanceSquare(min(x1, x2, x3, x4), min(Y1, y2, y3, y4), max(x1, x2, x3, x4), max(Y1, y2, y3, y4))) { // 겹친다.
				isOne = false;
			} else {
				isCrossed = false;
			}
		} else {
			// 한 점에서 만나지만, 한 점이 다른 직선 위에 있다. T자형
			// cout << "T " << endl;
			isOne = true;
			
			pair<double, double> c = crossPoint(x4, y4, x3, y3, x2, y2, x1, Y1);
			// cout << c.first << ' ' << c.second;
			u = c.first;
			v = c.second;
		}
	} else {
		isCrossed = false;
	}

	cout << isCrossed << endl;
	cout << fixed;
	cout.precision(9);
	if(isCrossed && isOne) {
		if((double)(lld)u == u && (double)(lld)v == v) {
			cout << (lld)u << ' '<< (lld)v;
		} else if((double)(lld)u == u) {
			cout << (lld)u << ' '<< v;
		} else if((double)(lld)v == v) {
			cout << u << ' ' << (lld)v;
		} else {
			cout << u << ' '<< v;
		}
	}
	
	return 0;
}
