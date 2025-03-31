#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int foo(lld x) {
	return x == 0 ? 0 : x > 0 ? 1 : -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	lld x1, y1, x2, y2;
	lld a1, b1, a2, b2;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> a1 >> b1 >> a2 >> b2;
	lld v1 = x2 - x1;
	lld v2 = y2 - y1;
	lld u1 = a2 - a1;
	lld u2 = b2 - b1;
	lld result1 = v1*(b1-y1) - v2*(a1-x1);
	lld result2 = v1*(b2-y1) - v2*(a2-x1);
	lld result3 = u1*(y1-b1) - u2*(x1-a1);
	lld result4 = u1*(y2-b1) - u2*(x2-a1);
	if(foo(result1) * foo(result2) < 0 && foo(result3) * foo(result4) < 0) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}

	return 0;
}