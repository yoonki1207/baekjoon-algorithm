#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int N, M, K;
vector<lld> arr;
vector<lld> tree;

lld init(int start, int end, int node) {
	if(start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

lld sum(int start, int end, int node, int left, int right) {
	if(left > end || right < start) return 0;
	if(left <= start && right >= end) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, lld diff) {
	if(index < start || index > end) return;
	tree[node] += diff;
	if(start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node*2, index, diff);
	update(mid + 1, end, node*2+1, index, diff);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	arr = vector<lld>(N);
	tree = vector<lld>(N*4);
	for(int i = 0; i < N; i++) cin >> arr[i];
	init(0, N-1, 1);
	for(int i = 0; i < M+K; i++) {
		lld a, b, c;
		cin >> a >> b >> c;
		if(a == 1) {
			lld s = sum(0, N-1, 1, b-1, b-1);
			update(0, N-1, 1, b-1, c-s);
		} else {
			lld s = sum(0, N-1, 1, (int)b-1, (int)c-1);
			cout << s << '\n';
		}
	}
	return 0;
}