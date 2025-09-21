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
#define MAX_N 500000
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int N, M;
vector<int> arr, tree, lazy;

int init(int start, int end, int n) {
	if(start == end) {
		return tree[n] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[n] = init(start, mid, n*2) ^ init(mid+1, end, n*2+1);
}


void lazyUpdate(int start, int end, int n) {
	if(start == end) {
		tree[n] ^= lazy[n];
		lazy[n] = 0;
		return;
	}
	if((end-start+1)%2==1) tree[n] ^= lazy[n];
	int mid = (start + end) / 2;
	lazy[n*2] ^= lazy[n];
	lazy[n*2+1] ^= lazy[n];
	lazy[n] = 0;
}

int query(int start, int end, int n, int left, int right) {
	if(right < start || end < left) return 0;
	lazyUpdate(start, end, n);
	if(left <= start && end <= right) {
		return tree[n];
	}
	int mid = (start + end) / 2;
	return query(start, mid, n*2, left, right) ^ query(mid+1, end, n*2+1, left, right);
}

// 만약 노드 전체를 업데이트 하는 거라면, 굳이 지금 업데이트 할 필요가 없지 않나.
// 즉 lazy로 둔 다음, 나중에 필요할때 업데이트 하면 된다.
void update(int start, int end, int n, int left, int right, int k) {
	if(right < start || end < left) return;
	if(left <= start && end <= right) { // 노드 전체를 lazy 업데이트한다.
		lazy[n] ^= k;
		return;
	}
	// 노드 전체가 아니라면 해당 노드를 업데이트한다. 
	int len = 
		(start <= left && right <= end) ? 
		right-left+1 : 
		min(end-left, right-start) + 1;
	if(len%2 == 1)
		tree[n] ^= k;

	// 그리고 다음 노드를 lazy에 올린다.
	int mid = (start + end) / 2;
	if(start == end) return;
	update(start, mid, n*2, left, right, k);
	update(mid+1, end, n*2+1, left, right, k);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	arr = vector<int>(N);
	tree = vector<int>(N*4);
	lazy = vector<int>(N*4);
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	init(0, N-1, 1);
	cin >> M;
	for(int m = 0; m < M; m++) {
		int op, i, j, k;
		cin >> op;
		if(op == 1) {
			cin >> i >> j >> k;
			update(0, N-1, 1, i, j, k);
		} else {
			cin >> i >> j;
			k = query(0, N-1, 1, i, j);
			cout << k << '\n';
			// cout << '[' << k << ']' << endl;
		}
	}
	
	return 0;
}

/*
5
1 2 3 4 5
5
2 0 4
1 2 4 9
2 0 4
1 2 4 9
2 0 4

5
1 2 3 4 5
5
2 4 4
1 0 3 9
2 4 4
2 0 4
2 0 0

5
1 2 3 4 5
3
2 0 0
1 0 0 9
2 0 0
*/