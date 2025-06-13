#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321
#define lld long long
#define ull unsigned long long
#define MAX_N 500000

using namespace std;

int n;
vector<int> hexan;
int ans = 7;
// int max_i;

void init() {
	hexan.push_back(0);
	hexan.push_back(1);
	// hexan.push_back(6);
	for(int i = 2; true; i++) {
		int k = i * 4 - 3 + hexan.back();
		hexan.push_back(k);
		if(k>1000000) break;
	}
	// cout << hexan.size() << endl;
}

int dfs(int x, int target, int depth) {
	// cout << x << endl;
	int ret = INF;
	if(depth >= ans || (target > 130 && depth > 4) || (target > 146858 && depth > 3) || (target > 26 && depth > 5) || depth > 6 || x > target) return ret;
	if(x == target) {
		ans = depth;
		return depth;
	}
	vector<int>::iterator iter = lower_bound(hexan.begin(), hexan.end(), target-x);
	int max_i = (int)(iter - hexan.begin());
	for(int i = max_i; i >= 0; i--) {
		if(x+hexan[i] > target || depth+1 >= ans) continue;
		int res = dfs(x + hexan[i], target, depth+1);
		ret = min(ret, res);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	init();
	cin >> n;
	// cout << *iter << " " << (int)(iter - hexan.begin())<< endl;
	cout << dfs(0, n, 0);
	return 0;
}
