#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 2000001
#define lld long long int

using namespace std;

int solve(vector<int> v, int m) {
	int ret = 0;
	while(!v.empty()) {
		int len = v.back();
		ret += len*2;
		for(int i = 0; i < m && !v.empty(); i++) {
			v.pop_back();
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> vp;
	vector<int> vn;
	int max_val = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x>0) vp.push_back(x);
		else vn.push_back(-x);
		max_val = max(max_val, x > 0 ? x : -x);
	}
	sort(vp.begin(), vp.end());
	sort(vn.begin(), vn.end());
	int a = solve(vp, m);
	int b = solve(vn, m);
	cout << a + b - max_val;
	return 0;
}
