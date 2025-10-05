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
#define MAX_N 15
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

lld N, k;

lld bruteCount(lld x) {
	lld ret = 0;
	for(int i = 1; i <= N; i++) {
		ret += min(N, x/i);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> N >> k;
	lld left = 1, right = N*N;
	lld bef = 0;
	while(left <= right) {
		lld mid = (left + right) / 2;
		lld cnt = bruteCount(mid);
		if(cnt < k) {
			bef = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	cout << bef+1;
	return 0;
}

// i*j가 있을 때 i*j보다 작은 수들의 갯수는?
/*
f(4) = 8
f(5) = 10
100000 1000000000
204535821%
*/