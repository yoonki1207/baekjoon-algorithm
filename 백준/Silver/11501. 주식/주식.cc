#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 2000001
#define lld long long int

using namespace std;

int arr[500000];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int T;
	cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;
		vector<lld> price(n);
		lld seed = 0;
		for(int i = 0; i < n; i++) cin >> price[i];
		lld max_p = price.back();
		for(int i = price.size() - 2; i >= 0; --i) {
			const lld p = price[i];
			max_p = max(max_p, p);
			if(max_p - p > 0) seed += max_p - p;
		}
		cout << seed << '\n';
	}
	return 0;
}
