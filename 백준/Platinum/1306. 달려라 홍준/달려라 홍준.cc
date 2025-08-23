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
#define MAX_N 1000001
#define lld long long int
using namespace std;

int N, M;
int tree[MAX_N*4];
int arr[MAX_N];

int init(int start, int end, int n) {
	int mid = (start + end) / 2;
	if(start == end) {
		return tree[n] = arr[start];
	}
	return tree[n] = max(init(start, mid, n*2), init(mid+1, end, n*2+1));
}

int query(int start, int end, int n, int left, int right) {
	if(right < start || left > end) return 0;
	if(left <= start && end <= right) return tree[n];
	int mid = (start + end) / 2;
	return max(query(start, mid, n*2, left, right), query(mid+1, end, n*2+1, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	init(0, MAX_N, 1);

	for(int i = M-1; i <= N-M; i++) {
		cout << query(0, MAX_N, 1, i-M+1, i+M-1) << ' ';
	}

	return 0;
}