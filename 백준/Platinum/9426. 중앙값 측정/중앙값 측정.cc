#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321
#define MAX_N 65537
#define lld long long int
using namespace std;

int N, K;
int tree[MAX_N*4];
int arr[MAX_N+1];

int query(int start, int end, int n, int pos) {
	if(start == end) return start;
	int mid = (start + end) / 2;
	if(tree[n*2] >= pos) {
		return query(start, mid, n*2, pos);
	} else {
		return query(mid+1, end, n*2+1, pos-tree[n*2]);
	}
}

void update(int start, int end, int n, int pos, int diff) {
	if(start > pos || end < pos) return;
	tree[n] += diff;
	if(start == end) {
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, n*2, pos, diff);
	update(mid+1, end, n*2+1, pos, diff);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >> N >> K;
	lld ans = 0;
	vector<int> v(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
		update(0, MAX_N, 1, v[i], 1);
		if(i >= K-1) {
			int q = query(0, MAX_N, 1, (K+1)/2);
			ans += (lld)q;
			update(0, MAX_N, 1, v[i-K+1], -1);
		}
	}
	cout << ans << endl;

	return 0;
}