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
#define PRN cout << "DEBUG" << endl

using namespace std;

int query(vector<int>& arr, int start, int end, int n, int left, int right) {
	if(left <= start && end <= right) {
		return arr[n];
	}
	if(left > end || right < start) {
		return 0;
	}
	int mid = (start + end) / 2;
	return query(arr, start, mid, n*2, left, right) + query(arr, mid+1, end, n*2+1, left, right);
}

void update(vector<int>& arr, int start, int end, int n, int pos, int diff) {
	if(start <= pos && pos <= end) {
		arr[n] += diff;
		if(start == end) return;
		int mid = (start + end) / 2;
		update(arr, start, mid, n*2, pos, diff);
		update(arr, mid+1, end, n*2+1, pos, diff);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T, test_case, N, M;
	cin >> T;
	for(test_case = 0; test_case < T; test_case++) {
		cin >> N >> M;
		vector<int> arr(4*(N+M));
		vector<int> index(N+1); // index[DVD] = arr에서의 DVD의 위치
		for(int i = 0; i < N; i++) {
			update(arr, 0, N+M, 1, i, 1);
			index[N-i] = i;
		}
		for(int i = 0; i < M; i++) {
			int pos;
			cin >> pos;
			int idx = index[pos];
			int result = query(arr, 0, N+M, 1, idx+1, N+i-1);
			update(arr, 0, N+M, 1, idx, -1);
			index[pos] = N+i;
			update(arr, 0, N+M, 1, N+i, 1);
			cout << result << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}