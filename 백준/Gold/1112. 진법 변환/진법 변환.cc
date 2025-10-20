#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int x, b;

pair<int, int> divmod(int p, int q) {
	int m = p / q;
	int n = p % q;
	if (p < 0 && q < 0 && n < 0) {
		n -= b;
		++m;
	}
	return { m, n };
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	x = -123456789;
	b = -7;
	bool isMinus = false;
	cin >> x >> b;
	if (b > 0 && x < 0) {
		isMinus = true;
		x = -x;
	}
	vector<int> ans;
	while (x != 0) {
		pair<int, int> res = divmod(x, b);
		ans.push_back(res.second);
		x = res.first;
	}
	if (ans.empty()) {
		cout << "0\n";
	}
	else {
		if (isMinus) cout << '-';
		while (!ans.empty()) {
			cout << ans.back();
			ans.pop_back();
		}
	}

	return 0;
}