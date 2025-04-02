#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int N, M, X;
vector<vector<int>> v;
vector<bool> visited;

int solve(int n) {
	vector<int> arr = v[n];
	int ret = 0;
	for(int i = 0; i < arr.size(); i++) {
		if(visited[arr[i]]) continue;
		visited[arr[i]] = true;
		ret += solve(arr[i]) + 1;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> N >> M;
	v = vector<vector<int>>(N+1);
	visited = vector<bool>(N+1);
	for(int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		v[b].push_back(a);
	}
	cin >> X;
	cout << solve(X) << endl;

	return 0;
}