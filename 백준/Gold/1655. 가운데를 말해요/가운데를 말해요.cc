#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#define INF 987654321
#define MAX_N 20001
#define lld long long

using namespace std;

// 백준 1655: 전형적인 segment tree 문제

int N;
vector<int> arr;
vector<int> tree;

void update(int start, int end, int n, int pos, int diff) {
	if (pos < start || pos > end) return;
	tree[n] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, n * 2, pos, diff);
	update(mid + 1, end, n * 2 + 1, pos, diff);
}

int query(int start, int end, int n, int m) { // m starts with 0
	// 1001001000 -> find m=1 == left have to 1 and val is 1
	// 0010000 -> find m = 0 == left have to 0 and val is 1
	if (start == end) return start;
	int left_query  = tree[2 * n];
	int right_query = tree[2 * n + 1];
	int mid = (start + end) / 2;
	if (left_query >= m + 1) {
		return query(start, mid, n * 2, m);
	}
	else {
		return query(mid + 1, end, n * 2 + 1, m - left_query);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	arr = vector<int>(N);
	tree = vector<int>(MAX_N * 4);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i] += 10'000;

		update(0, MAX_N, 1, arr[i], 1);
		int q = query(0, MAX_N, 1, i / 2);
		cout << q - 10000<< '\n';
	}

	return 0;
}
