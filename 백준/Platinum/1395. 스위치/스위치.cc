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
#define MAX_N 100000
#define lld long long int
using namespace std;

int N, M;
int tree[MAX_N*4];
int lazy[MAX_N*4];

inline void updateLazy(int start, int end, int n) {
	if(lazy[n] % 2 == 1) {
		tree[n] = (end - start + 1) - tree[n]; // update
		if(start != end) {
			lazy[n*2] += lazy[n];
			lazy[n*2+1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

int query(int start, int end, int n, int left, int right) {
	updateLazy(start, end, n);
	if(right < start || left > end) return 0;
	if(left <= start && end <= right) return tree[n];
	int mid = (start+end) / 2;
	return
		query(start, mid, n*2, left, right) +
		query(mid+1, end, n*2+1, left, right);
}

void update(int start, int end, int n, int left, int right) {
	updateLazy(start, end, n);
	if(right < start || left > end) return;
	if(left <= start && end <= right) { // completely inside
		tree[n] = (end - start + 1) - tree[n]; // switch
		if(start != end) { // if not a leaf node
			// lazy update for children
			lazy[n*2] += 1; 
			lazy[n*2+1] +=1;
		}
		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, n*2, left, right);
	update(mid+1, end, n*2+1, left, right);
	tree[n] = tree[n*2] + tree[n*2+1];
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int c, a, b;
		cin >> c >> a >> b;
		if(c == 0) {
			update(0, N-1, 1, a-1, b-1);
		} else {
			cout << query(0, N-1, 1, a-1, b-1) << '\n';
		}
	}

	return 0;
}