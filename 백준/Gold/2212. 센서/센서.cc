#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 2000001
#define lld long long int

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for(int i = 1; i < n; i++) v[i-1] = v[i] - v[i-1];
	sort(v.begin(), v.end()-1);
	int ans = 0;
	for(int i = 0; i < n-k; i++) {
		// cout << v[i] << ' ';
		ans += v[i];
	}
	cout << ans;
	return 0;
}

/**
 2 3 0 1 2
1 3 6 6 7 9
1 2 3 4 5 6 7 8 9
1 0 1 0 0 2 1 0 1
0 1 0 0 0 0 1 0 0
 */