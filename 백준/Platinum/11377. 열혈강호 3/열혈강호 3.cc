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
#define MAX_N 1001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int N, M, K;
vector<int> adj[MAX_N];

bool done[MAX_N];
int slt[MAX_N];

bool dfs(int x) {
	for(int i = 0; i < adj[x].size(); i++) {
		int p = adj[x][i];
		if(done[p]) continue;
		done[p] = true;
		if(slt[p] == 0 || dfs(slt[p])) {
			slt[p] = x;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n, x;
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++) {
		cin >> n;
		for(int j = 0; j < n; j++) {
			cin >> x;
			adj[i].push_back(x);
		}
	}
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		fill(done, done+MAX_N, false);
		if(dfs(i)) cnt++;
	}
	for(int i = 1; i <= M && K > 0; i++) {
		fill(done, done+MAX_N, false);
		if(dfs(i)) {
			K--;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
