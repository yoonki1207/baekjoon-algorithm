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
#define MAX_N 20001
#define lld long long int
using namespace std;

int id, d[MAX_N];
bool finished[MAX_N];
vector<int> arr[MAX_N];
vector<vector<int>> SCC;
vector<int> s;

int dfs(int x) {
	d[x] = ++id;
	s.push_back(x);

	int parent = d[x];
	for(int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];
		if(d[y] == 0) parent = min(parent, dfs(y));
		else if(!finished[y]) parent = min(parent, d[y]);
	}

	if(parent == d[x]) {
		vector<int> scc;
		while(1) {
			int t = s.back();
			s.pop_back();
			scc.push_back(t);
			finished[t] = true;
			if(t == x) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int N, M, a, b;
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		cin >> a >> b; // !a -> b
		if(a < 0) a = -a; else a = a+N;
		if(b < 0) b = -b + N;
		arr[a].push_back(b);
		if(a > N) a -= N; else a += N;
		if(b > N) b -= N; else b += N;
		arr[b].push_back(a);
	}

	for(int i = 1; i <= N*2; i++) {
		if(d[i] == 0) dfs(i);
	}

	int ans = 1;
	for(int i = 0; i < SCC.size(); i++) {
		for(int j = 0; j < SCC[i].size(); j++) {
			for(int k = 0; k < SCC[i].size(); k++) {
				if(abs(SCC[i][j] - SCC[i][k]) == N) {
					ans = 0;
				}
			}
		}
	}
	cout << ans;

	return 0;
}