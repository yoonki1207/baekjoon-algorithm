#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#define INF 987654321
#define MAX_N 2000001
#define lld long long int

using namespace std;

// int drr[1001];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int T;
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		vector<int> arr(n);
		for(int i = 0; i < n; i++) {
			int k = i;
			if(i % 2 == 0) {
				k = i / 2;
			} else {
				k = n - i / 2 - 1;
			}
			arr[k] = v[i];
		}
		int max_diff = abs(arr[0] - arr[n-1]);
		for(int i = 1; i < n; i++) {
			max_diff = max(max_diff, abs(arr[i] - arr[i-1]));
		}
		cout << max_diff << '\n';
	}
	return 0;
}
