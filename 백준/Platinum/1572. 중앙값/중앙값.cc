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

int N, K, k2;
int tree[MAX_N*4];

int query(int start, int end, int n, int cnt) {
	if(start == end) return start;
	int mid = (start + end) / 2;
	if(tree[n*2] < cnt) return query(mid + 1, end, n*2+1, cnt-tree[n*2]);
	else return query(start, mid, n*2, cnt);
}
void update(int start, int end, int n, int pos, int diff) {
	if(start > pos || end < pos) return;
	int mid = (start + end) / 2;
	tree[n] += diff;
	if(start == end) return;
	update(start, mid, n*2, pos, diff);
	update(mid+1, end, n*2+1, pos, diff);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> K;
	vector<int> v(N);
	lld ans = 0;
	for(int i = 0; i < N; i++) {
		cin >> v[i];
		update(0, MAX_N, 1, v[i], 1);
		if(i+1 >= K) {
			int val = query(0, MAX_N, 1, (K+1)/2);
			ans += val;
			update(0, MAX_N, 1, v[i+1-K], -1);
		}
	}
	cout << ans;
	return 0;
}