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
#define MAX_N 500000

using namespace std;

int N; // 500,000  1,000,000,000
vector<int> v;
int arr[4*MAX_N];

int query(int start, int end, int n, int left, int right) {
	if(left > end || right < start) return 0;
	if(start >= left && right >= end) {
		return arr[n];
	} else {
		int mid = (start + end) / 2;
		return query(start, mid, n*2, left, right) + query(mid+1, end, n*2+1, left, right);
	}
}

void update(int start, int end, int n, int pos, int diff) {
	// cout << "update " << start << ' ' << end << ' ' << n << endl;
	if(pos < start || pos > end) return;
	if(start > end) return;
	arr[n] += diff;
	if(start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, n*2, pos, diff);
	update(mid+1, end, n*2+1, pos, diff);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	// for(int i = 0; i < 10; i++) {
	// 	update(0, 9, 1, i, i);
	// }
	// cout << query(0, 9, 1, 2, 9);
	
	
	cin >> N;
	v = vector<int>(N);
	priority_queue<pair<int, int>> pq; // -stat, idx
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		pq.push({-x, i});
	}
	int real_stat = 1;
	while(!pq.empty()) {
		int stat = -pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		v[idx] = real_stat;
		real_stat++;
	}
	// cout << v.size();
	// for(int i = 0; i < v.size(); i++) {
	// 	cout << v[i] << ' ';
	// }

	vector<int> ans;

	for(int i = 0; i < v.size(); i++) {
		update(0, N-1, 1, v[i]-1, 1);
		ans.push_back(i+2 - query(0, N-1, 1, 0, v[i]-1));
	}
	for(int i = 0; i < N; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}
/*

2 8 10 7 1 9 4 15
1 2 3  2 1 3 2 4

1 1 1  3 5 2 5 1

2
2 8
2 8 10
2 7 8 10
1 2 7 8 10
1 2 7 8 9 10
1 2 4 7 8 9 10
1 2 4 7 8 9 10 15

2
8 2
10 8 2
10 8 7 2
10 8 7 2 1
10 9 8 7 2 1
10 9 8 7 4 2 1
15 10 9 8 7 4 2 1

2 8 10 7 1 9 4 15
1 2 3  4 5 6 7 8

1 2 4 7 8 9 10 15
5 1 7 4 2 6 3  8


2 8 10 7 1 9 4 15
각 선수들이 입장할 때
최대 등수 = 입장 순서 - (선수보다 능력 낮은 선수들의 인원수)

1: 2입장, (1 - sumRange(0, 1)) = 1
2: 8입장, (2 - sumRange(0, 7)) = 1



*/