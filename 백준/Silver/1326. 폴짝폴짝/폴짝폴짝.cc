#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// int arr[10000][10000];
int visited[10000];
int stones[10000];
int n;
int start_point, end_point;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> stones[i];
	}
	cin >> start_point >> end_point;

	queue<pair<int, int>> q;
	visited[start_point-1] = 1;
	int ret = -1;
	q.push({start_point - 1, 0});
	while(!q.empty()) {
		int index = q.front().first;
		int jumps = q.front().second;
		q.pop();
		if(index == end_point-1) {
			ret = jumps;
			break;
		}
		for(int next_index = index + stones[index]; next_index < n; next_index+=stones[index] ) {
			if(!visited[next_index]) {
				visited[next_index] = 1;
				q.push({next_index, jumps+1});
			}
		}

		for(int next_index = index - stones[index]; next_index >= 0; next_index-=stones[index] ) {
			if(!visited[next_index]) {
				visited[next_index] = 1;
				q.push({next_index, jumps+1});
			}
		}
	}
	cout << ret;
	
	return 0;
}
/**
2 2 2 2 1
0 0 1 0 1
 */