#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#define lld long long int
#define MAX_N 10000002

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	lld W, H, f, c, x1, y1, x2, y2;
	cin >> W  >> H >> f >> c >> x1 >> y1 >> x2 >> y2;
	if(f > W / 2) f = W - f;
	// f까지의 W가 2
	lld q = (c+1) * 2;
	lld p = c+1;
	lld w1 = max(f - x1, (lld)0);
	lld w2 = (x2 - x1 - w1);
	if(f > x2) {
		w1 = x2 - x1;
		w2 = 0;
	}
	lld ans = (w1*q + w2*p)*(y2-y1);
	cout << (lld)(W*H - ans) << '\n';
	return 0;
}