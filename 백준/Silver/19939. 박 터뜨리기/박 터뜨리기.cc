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
	int n, k;
	cin >> n >> k;
	int ans = -1;
	if(k*(k+1)/2 > n) {
		cout << ans << endl; 
	} else {
		int tmp = n - k*(k+1)/2;
		if(tmp % k == 0) {
			ans = k-1;
		} else {
			ans = k;
		}
		cout << ans << endl;
	}
	return 0;
}