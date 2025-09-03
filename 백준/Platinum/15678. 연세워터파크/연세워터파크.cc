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
#define INF 987654321
#define MAX_N 100000
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int N, D;
vector<lld> v;
vector<lld> dp;
lld tree[MAX_N*4];

lld query(int start, int end, int n, int left, int right) {
	if(start > right || end < left) return 0;
	if(left <= start && end <= right) return tree[n];
	int mid = (start + end) / 2;
	return max(query(start, mid, n*2, left, right), query(mid + 1, end, n*2+1, left, right));
}

void update(int start, int end, int n, int pos, lld diff) {
	if(start > pos || end < pos) return;
	// tree[n] += diff;
	if(start == end) {
		tree[n] += diff;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, n*2, pos, diff);
	update(mid + 1, end, n*2+1, pos, diff);
	tree[n] = max(tree[n*2], tree[n*2+1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef DEBUG
	cin >> N >> D;
	v = vector<lld>(N);
	dp = vector<lld>(N);
	for(int i = 0; i < N; i++) cin >> v[i];
#endif
#ifdef DEBUG
	N = 100000;
	D = N-1;
	v = vector<lld>(N);
	dp = vector<lld>(N);
	for(int i = 0; i < N; i++) v[i] = 1;
#endif

	lld ans = v[0];
	for(int i = N-1; i >= 0; i--) {
		if(i == N-1) {
			dp[i] = v[i];
		} else {
			dp[i] = query(0, N-1, 1, i, min(N-1, i+D)) + v[i];
		}
		update(0, N-1, 1, i, dp[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;



	return 0;
}

// 2 7 5 -4 10 -5 -5 -5 30 -10