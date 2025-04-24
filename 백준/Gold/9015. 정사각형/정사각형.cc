#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

/* Definitions */
map<pair<int, int>, int> cached_coords;
vector<pair<int, int>> v;

/* Functions */
bool isExist(int y, int x) {
	return cached_coords.find({y, x}) != cached_coords.end();
}

int getArea(pair<int, int> a, pair<int, int> b) {
	return 
		(a.first - b.first) * (a.first - b.first) +
		(a.second - b.second) * (a.second - b.second);
}

int getSquareArea(pair<int, int> a, pair<int, int> b) {
	pair<int, int> c, d;
	int dx = b.second - a.second;
	int dy = b.first - a.first;
	c.second = b.second - dy;
	c.first = b.first + dx;
	d.second = a.second - dy;
	d.first = a.first + dx;
	if(isExist(c.first, c.second) && isExist(d.first, d.second)) {
		return getArea(a, b);
	} 
	c.second = b.second - dy;
	c.first = b.first + dx;
	d.second = a.second - dy;
	d.first = a.first + dx;
	if(isExist(c.first, c.second) && isExist(d.first, d.second)) {
		return getArea(a, b);
	} 
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while(T-->0) {
		int n; cin >> n;
		v = vector<pair<int, int>>(n);
		cached_coords.clear();
		for(int i = 0; i < n; i++) {
			int y, x;
			cin >> x >> y;

			v[i] = {y, x};
			cached_coords.insert({{y, x}, i});
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				int s = getSquareArea(v[i], v[j]);
				// cout << v[i].second << ' ' << v[i].first << ' ' << v[j].second << ' ' << v[j].first << endl;
				ans = max(ans, s);
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}