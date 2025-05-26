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
#define MAX_N 1000001

using namespace std;

int N;
int arr[1000001];
int A[1000001];
int brr[1000001];
int B[1000001];
int node[1000001];
int tree[2000000];

int sum(int start, int end, int node, int left, int right) {
	if(left <= start && end <= right) return tree[node];
	if(left > end || right < start) return 0;
	int mid = (start + end) / 2;
	return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, int diff) {
	if(index < start || index > end) return;
	tree[node] += diff;
	if(start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node*2, index, diff);
	update(mid+1, end, node*2+1, index, diff);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x;
	lld ans = 0;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
		A[arr[i]] = i;
	}
	for(int i = 0; i < N; i++) {
		cin >> brr[i];
		B[brr[i]] = i;
	}
	for(int i = 0; i < N; i++) {
		int val = arr[i];
		int index = B[val];
		ans += (lld)sum(0, N-1, 1, index, N-1);
		update(0, N-1, 1, index, 1);
	}
	cout << ans << endl;
	return 0;
}