#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321
#define MAX_N 1000001
#define lld long long int
using namespace std;

int solve(int n) {
	int ret = 0;
	for(int size = 1; size <= n; size++) {
		int tip = size * (size - 1) / 2;
		if(tip > n) break;
		if((n - tip) % size == 0 && n - tip > 0) {
			ret++;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	cout << solve(n);

	return 0;
}