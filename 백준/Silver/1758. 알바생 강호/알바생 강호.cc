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
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), greater());
	lld ans = 0;
	for(int i = 0; i < n; i++) {
		ans += max(0, v[i]-i);
	}
	cout << ans;
	return 0;
}