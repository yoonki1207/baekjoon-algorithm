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
#define MAX_N 100000
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int N, M, a, b, c;
vector<int> tree[MAX_N*4];
vector<int> v;

void init(int start, int end, int n) {
	if(start == end) {
		tree[n].push_back(v[start]);
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, n*2);
	init(mid+1, end, n*2+1);
	vector<int>& left = tree[n*2];
	vector<int>& right = tree[n*2+1];
	vector<int>::iterator l = left.begin();
	vector<int>::iterator r = right.begin();
	while(l != left.end() || r != right.end()) {
		if(l == left.end()) {
			tree[n].push_back(*r++);
		} else if(r == right.end()) {
			tree[n].push_back(*l++);
		} else {
			if(*l < *r) tree[n].push_back(*l++);
			else tree[n].push_back(*r++);
		}
	}
}

int query(int start, int end, int n, int left, int right, int k) {
	if(right < start || end < left) return 0;
	if(left <= start && end <= right) {
		return tree[n].end() - upper_bound(tree[n].begin(), tree[n].end(), k);
	}
	int mid = (start + end) / 2;
	return query(start, mid, n*2, left, right, k) + query(mid+1, end, n*2+1, left, right, k);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	v = vector<int>(N);
	for(int i = 0; i < N; i++) cin >> v[i];
	init(0, N-1, 1);

	cin >> M;
	int result;
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		result = query(0, N-1, 1, a-1, b-1, c);
		cout << result << '\n';
	}

	return 0;
}
