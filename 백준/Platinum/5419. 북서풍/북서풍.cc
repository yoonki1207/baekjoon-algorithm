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
#define MAX_N 75000
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int T, N;
int tree[MAX_N*4];

int query(int start, int end, int n, int left, int right) {
	if(start > right || end < left) return 0;
	if(left <= start && end <= right) return tree[n];
	int mid = (start + end) / 2;
	return query(start, mid, n*2, left, right) + query(mid+1, end, n*2+1, left, right);
}

void update(int start, int end, int n, int pos, int diff) {
	if(start > pos || end < pos) return;
	tree[n] += diff;
	if(start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, n*2, pos, diff);
	update(mid+1, end, n*2+1, pos, diff);
	return;
}

int customSort(const pii& a, const pii& b) {
	return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int x, y;
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++) {
		memset(tree, 0, sizeof(tree));
		cin >> N;
		vector<pii> islands(N);
		for(int i = 0; i < N; i++) {
			cin >> islands[i].first >> islands[i].second;
			islands[i].second *= -1;
		}
		sort(islands.begin(), islands.end(), customSort);
		int k = islands[0].second;
		int cnt = 0;
		for(int i = 0; i < N; i++) {
			if(islands[i].second == k) {
				islands[i].second = cnt;
			} else {
				k = islands[i].second;
				islands[i].second = ++cnt;
			}
		}
		sort(islands.begin(), islands.end());
		// sort(islands.begin(), islands.end());
		// x에 대해서 query 및 update, query시 자기자신 포함
		// x기준 오름차순, y삽입
		lld ans = 0;
		for(int i = 0; i < N; i++) {
			ans += query(0, N, 1, 0, islands[i].second);
			// cout << "query: " << query(0, max_x-1, 1, 0, islands[i].second) << endl;
			update(0, N, 1, islands[i].second, 1);
			// cout << islands[i].first << ' ' << islands[i].second <<  ' ' << ans << endl;
		}
		cout << ans << '\n';
		// for(int i = 0; i < N; i++) {
			
		// }
	}
	return 0;
}
/*
4
-10 -10
-10 10
10 -10
10 10

-10, 10
10, 10
-10, -10
10, -10

1. 좌표 압축
-10 -> 0, 10 -> 1
2. 2차원 구간 합 만들기
각 좌표에 대해서 점 개수 세기

*/