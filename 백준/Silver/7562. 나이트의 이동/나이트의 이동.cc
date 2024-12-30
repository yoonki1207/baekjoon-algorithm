#include <iostream>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

int t, n;
int offset[8][2] = {{-2, -1},{-2,1},{2,-1},{2,1},{1,-2},{1,2},{-1,-2},{-1,2}};

void solve(int a, int b, int (*arr)[300]) {
	
	queue<pair<int, pair<int, int>>> q;
	arr[a][b] = 0;
	q.push({1, {a, b}});
	while(!q.empty()) {
		int depth = q.front().first;
		pair<int, int> coord = q.front().second;
		q.pop();
		// if(arr[coord.first][coord.second] != INF) continue;
		for(int i = 0; i < 8; i++) {
			int y = coord.first + offset[i][0];
			int x = coord.second + offset[i][1];
			if(y < 0 || y >= n || x < 0 || x >= n) continue;
			if(arr[y][x] > depth) {
				arr[y][x] = depth;
				q.push({depth+1,{y, x}});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> t;
	while(t-->0){
		cin >> n;
		int a, b; cin >> a >> b;
		int c, d; cin >> c >> d;
		int arr[300][300] = {0};
		for(int i = 0; i < 300*300; i++)arr[i%300][i/300]=INF;
		solve(a, b, arr);
		// for(int i = 0; i < n; i++) {
		// 	for(int j = 0; j < n; j++) {
		// 		cout << arr[i][j] << ' ';
		// 	}cout << endl;
		// }
		cout << arr[c][d] << endl;
	}
	return 0;
}
/**
3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
 */