#include <iostream>
#include <algorithm>

using namespace std;

int cache[41] = {1, 1, 2, 0};

int fibb(int i) {
	int& ret = cache[i];
	if(ret) return ret;
	return ret = fibb(i-1) + fibb(i-2);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, m, ans = 1, offset = 0;
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int x; cin >> x;
		ans *= fibb(x-offset - 1);
		offset = x;
	}
	ans *= fibb(n-offset);

	cout << ans;

	return 0;
}