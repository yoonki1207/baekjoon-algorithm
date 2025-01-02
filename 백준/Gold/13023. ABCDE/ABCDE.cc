#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

typedef struct Node {
	vector<int> friends;
} Node;

int n;
int m;
bool arr[2001][2001];
int len = 0;

bool dfs(int index, int length, vector<Node>& v, vector<bool>& visited) {
	if(length == 4) {
		return true;
	}
	int ret = false;
	visited[index] = true;
	for(vector<int>::iterator iter = v[index].friends.begin(); iter != v[index].friends.end(); iter++) {
		if(!visited[*iter]) {
			if(dfs(*iter, length+1, v, visited)) return true;
			// if(ret) return true;
		}
	}
	visited[index] = false;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	vector<Node> v(n);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].friends.push_back(b);
		v[b].friends.push_back(a);
		arr[a][b] = arr[b][a] = true;
	}
	bool ans = false;
	int last = 0;
	vector<bool> visited(n);
	for(int i = 0; i < n; i++) {
		ans = dfs(i, 0, v, visited);
		if(ans) break;
	}
	cout << ans;
	return 0;
}