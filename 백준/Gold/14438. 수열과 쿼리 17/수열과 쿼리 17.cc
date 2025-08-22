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
int arr[MAX_N+1];

int init(int start, int end, int n) {
	if(start == end) {
		return tree[n] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[n] = min(init(start, mid, n*2), init(mid + 1, end, n*2+1));
}

int query(int start, int end, int n, int left, int right) {
	if(right < start || end < left) return 2100000000;
	if(left <= start && end <= right) return tree[n];
	int mid = (start + end) / 2;
	return min(query(start, mid, n*2, left, right), query(mid+1, end, n*2+1, left, right));
}

int update(int start, int end, int n, int pos, int diff) {
	if(start > pos || end < pos) return tree[n];
	if(start == end) {
		return tree[n] = diff;
	}
	int mid = (start + end) / 2;
	return tree[n] = min(update(start, mid, n*2, pos, diff), update(mid+1, end, n*2+1, pos, diff));
	// tree[n] = min(tree[n], diff);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int a, b, c;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	init(0, N-1, 1);
	cin >> M;
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if(a == 1) {
			// int& prev_val = arr[b-1];
			// int prev_val = query(0, N-1, 1, b-1, b-1);
			// int diff = c - prev_val;
			update(0, N-1, 1, b-1, c);
			// prev_val += diff;
		} else {
			cout << query(0, N-1, 1, b-1, c-1) << '\n';
		}
	}

	return 0;
}