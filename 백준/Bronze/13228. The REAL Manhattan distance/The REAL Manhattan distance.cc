#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		int x = c + f + abs(a - d) + abs(b - e);
		cout << x << '\n';
	}
	return 0;
}