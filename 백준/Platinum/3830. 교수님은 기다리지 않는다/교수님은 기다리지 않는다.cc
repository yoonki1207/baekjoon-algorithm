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
#define MAX_N 100001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int N, M;
int p[MAX_N];
lld dist[MAX_N];

int find(int x) {
	if(p[x] == -1) return x;
	int parent = find(p[x]); // x의 부모 p
	dist[x] += dist[p[x]]; // p2부모 의 거리 + x2p의 거리 = x2부모
	return p[x] = parent;
}

void merge(int a, int b, int w) {
	int pa = find(a);
	int pb = find(b);
	if(pa == pb) return;
	dist[pb] = dist[a] - dist[b] + w;
	p[pb] = pa;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	while(true) {
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		fill(p, p+MAX_N, -1);
		fill(dist, dist+MAX_N, 0);
		char op;
		int a, b, w;
		for(int i = 0; i < M; i++) {
			cin >> op;
			if(op == '!') {
				cin >> a >> b >> w;
				merge(a, b, w);
			} else {
				cin >> a >> b;
				if(find(a) != find(b)) {
					cout << "UNKNOWN\n";
				} else {
					cout << dist[b] - dist[a] << '\n';
				}
			}
		}
	}
	
	return 0;
}