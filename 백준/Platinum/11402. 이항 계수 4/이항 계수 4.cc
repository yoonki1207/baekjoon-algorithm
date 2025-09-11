#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#include <string.h>
#define INF 987654321
#define MAX_N 102
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

lld cache[2001][2001];
int M;

vector<int> getLuca(lld n, int p) {
	vector<int> ret;
	while(n > 0) {
		ret.push_back(n%p);
		n /= p;
	}
	return ret;
}

lld comb(int n, int r) {
	if(n < r) return 0;
	if(r>n/2) r = n-r;
	if(cache[n][r] != 0) return cache[n][r];
	if(r == 0) return 1;
	if(r == 1) return cache[n][r] = n;
	return cache[n][r] = (comb(n-1, r-1)%M + comb(n-1, r)%M)%M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	lld N, K;
	cin >> N >> K >> M;
	vector<int> v1 = getLuca(N, M);
	vector<int> v2 = getLuca(K, M);
	int len = min(v1.size(), v2.size());
	lld ans = 1;
	for(int i = 0; i < len; i++) {
		lld res = comb(v1[i], v2[i]);
		ans *= res;
		ans %= M;
	}
	cout << ans << endl;
	return 0;
}