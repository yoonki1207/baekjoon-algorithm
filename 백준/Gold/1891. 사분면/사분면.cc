#include <iostream>
#include <vector>
#include <string>
#include <math.h>

#define lld long long

using namespace std;

typedef struct Coord {
	lld x;
	lld y;
} Coord; // 왼쪽 아래가 0, 0이다

int cache[2][2] = { {3, 2}, {4, 1} }; //cache[x][y];
Coord reverseCache[5] = { {0, 0}, {1, 1}, {0, 1}, {0, 0}, {1, 0} };

vector<int> getArea(Coord coord, int n) {
	vector<int> v;
	for (int i = 0; i < n; i++) {
		v.push_back(cache[coord.x % 2][coord.y % 2]);
		coord.x /= 2;
		coord.y /= 2;
	}
	return v;
}

string vtscc(const vector<int> v) {
	string ret = "";
	vector<int> tmp = v;
	while (!tmp.empty()) {
		ret += tmp.back()+'0'; tmp.pop_back();
	}
	return ret;
}

Coord getCoord(string s, int n) {
	Coord ret = { 0, 0 };
	for (int i = 0; i < n; i++) {
		Coord tmp = reverseCache[s[i]-'0'];
		lld p = pow(2, n - i - 1);
		ret.x += tmp.x * p;
		ret.y += tmp.y *p;
	}
	return ret;
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	lld n, x, y;
	string t;
	cin >> n >> t;
	cin >> x >> y;
	Coord coord = getCoord(t, n);
	coord.x += x;
	coord.y += y;
	//cout << coord.x << ' ' << coord.y << endl;
	if (coord.x < 0 || coord.y < 0 || coord.x >= pow(2, n) || coord.y >= pow(2, n)) {
		cout << -1 << endl;
	}
	else {
		string s = vtscc(getArea(coord, n));
		cout << s << endl;
	}
	return 0;
}

/*
     3 1
%2   1 1 -> 1
/2%2 1 0 -> 4 (1, 0)
/2%2 0 0 -> 3
  
     5 2
%2   1 0 -> 4
/2%2 0 1 -> 2 (2, 1)
/2%2 1 0 -> 4

3 -> 0 0 * 2^2
4 -> 1 0 * 2^1
1 -> 1 1 * 2^0
+    3 1
*/