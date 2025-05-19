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

int N, M;
vector<int> v;
vector<int> tree;

int init(int start, int end, int node) {
	if(start == end) {
		return tree[node] = v[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = min(init(start, mid, node*2), init(mid+1, end, node*2+1));
}

int calc(int start, int end, int node, int left, int right) {
	if(left <= start && end <= right) return tree[node];
	if(left > end || right < start) return 1000000001;
	int mid = (start + end) / 2;
	return min(calc(start, mid, node * 2, left, right), calc(mid + 1, end, node * 2 + 1, left ,right));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> M;
	v = vector<int>(N);
	tree = vector<int>(N*4);

	// input array
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}

	init(0, N-1, 1);
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int result = calc(0, N-1, 1, a-1, b-1);
		cout << result << '\n';
	}
	
	return 0;
}