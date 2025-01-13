#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#define INF 987654321
#define MAX_N 2000001
#define lld long long

using namespace std;

// int drr[1001];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(a-b);
	}
	sort(v.begin(), v.end());
	if(n%2 == 1) {
		cout << 1 << endl;
	} else {
		int i = n/2;
		int ret = v[i] - v[i-1]+1;
		cout << ret << endl;
	}
	return 0;
}
