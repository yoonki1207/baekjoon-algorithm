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

int N, M, ans = 0;
vector<int> network[101];
int node[101];

bool dfs(int pos, vector<bool>& visited) {
	for(int i = 0; i < network[pos].size(); i++) {
		int next = network[pos][i];
		if(visited[next]) {
			continue;
		}
		visited[next] = true;
		if(node[next] == 0 || dfs(node[next], visited)) {
			node[next] = pos;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	// input
	cin >> N >> M;
	int a, b;
	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		network[a].push_back(b);
	}
	// input finish
	// N = 100;
	// M = 500;
	// for(int i = 1; i <= N; i++) {
	// 	for(int j = 1; j <= M/N; j++) {
	// 		network[i].push_back(j);
	// 	}
	// }
	

	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		vector<bool> visited(N+1);
		if(dfs(i, visited)) {
			cnt++;
		}
	}
	
	cout << cnt << endl;

	return 0;
}