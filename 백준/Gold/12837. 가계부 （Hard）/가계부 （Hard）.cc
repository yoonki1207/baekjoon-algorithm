#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int N, Q;
lld arr[1000001];
lld tree[1000001*4];

// start: 시작 인덱스, end: 끝 인덱스 
// left, right: 구간 합을 구하고자 하는 범위
lld sum(int start, int end, int node, int left, int right) {
	// 범위가 벗어나면
	if(left > end || right < start) return 0;
	// 범위 안이라면 
	if(left <= start && end <= right) return tree[node];
	// 그렇지 않다면 두 부분으로 나누어 합을 구하기
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, lld dif) {
	// 범위 밖에 있는 경우
	if(index < start || index > end) return;
	// 밤위 안이라면 내려가면서 다른 원소도 갱신
	tree[node] += dif;
	if(start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node*2,   index, dif);
	update(mid+1, end, node*2+1, index, dif);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for(int q = 0; q < Q; q++) {
		int x, a, b;
		cin >> x >> a >> b;
		if(x == 1) {
			update(1, N, 1, a, b);
		} else {
			lld result = sum(1, N, 1, a, b);
			cout << result << '\n';
		}
	}
	return 0;
}
