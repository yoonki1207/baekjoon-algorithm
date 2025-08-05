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
#define MAX_N 1000000
#define lld long long int

using namespace std;

int N;
int tree[MAX_N+1];


void update(int pos, int diff) {
	for(int i = pos; i <= N; i += i & -i) {
		tree[i] += diff;
	}
}

int query(int pos) {
	int ret = 0;
	for(int i = pos; i > 0; i -= i & -i) {
		ret += tree[i];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	vector<int> v(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}
	lld ans = 0;
	while(!v.empty()) {
		int x = v.back();
		v.pop_back();
		update(x, 1);
		ans += query(x-1);
	}
	cout << ans;
	return 0;
}

/*
4 2 7 1 5 6 3

0 0 0 0 0 0 0
0 0 1 0 0 0 0
0 0 1 0 0 1 0 // 6,3
0 0 1 0 1 1 0 // 5,3
1 0 1 0 1 1 0
1 0 1 0 1 1 1 // 7,1 7,3 7,5
1 1 1 0 1 1 1 // 2,1
1 1 1 1 1 1 1 // 4,3 4,2 4,1

*/