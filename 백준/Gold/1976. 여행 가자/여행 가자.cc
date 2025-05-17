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
int arr[200];

int getParent(int a) {
	if(arr[a] != a) return arr[a] = getParent(arr[a]);
	return a;
}

void unionNode(int a, int b) {
	int pa = getParent(a);
	int pb = getParent(b);
	if(pa != pb) arr[pb] = pa;
}

void init(int n) {
	for(int i = 0; i < n; i++) {
		arr[i] = i;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	init(N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			int x; cin >> x;
			if(x == 1)
			unionNode(i, j);
		}
	}
	bool result = true;
	if(M>0) {
		int x;
		cin >> x;
		int k = getParent(x-1);
		for(int i = 1; i < M; i++) {
			cin >> x;
			if(k != getParent(x-1)) {
				result = false;
			}

		}
	}
	cout << (result ? "YES" : "NO") << '\n';
	
	return 0;
}