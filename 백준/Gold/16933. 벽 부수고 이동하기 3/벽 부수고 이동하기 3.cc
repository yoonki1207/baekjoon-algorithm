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
#define PRN cout << "DEBUG" << endl

using namespace std;

int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N, M, K;
vector<vector<int>> world;
bool visited[1000][1000][10];

typedef struct Node {
	int y;
	int x;
	int k;
	int t;
	int moved;
} Node;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> N >> M >> K;
	string s;
	world = vector<vector<int>>(N, vector<int>(M));
	for(int i = 0; i < N; i++) {
		cin >> s;
		for(int j = 0; j < M; j++) {
			world[i][j] = (s[j] == '0' ? 0 : 1);
		}
	}
	Node node = {0, 0, 0, 0, 1};
	queue<Node> q;
	int ans = INF;
	q.push(node);
	visited[0][0][0] = true;
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int k = q.front().k;
		int t = q.front().t;
		int moved = q.front().moved;
		q.pop();
		// cout << y << ' ' << x << ' ' << k << ' ' << t << ' ' << moved << endl;
		if(y == N - 1 && x == M - 1) {
			ans = moved;
			break;
		}
		for(int i = 0; i < 4; i++) {
			int ny = y + r[i][0];
			int nx = x + r[i][1];
			if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if(world[ny][nx] == 1 && k < K && visited[ny][nx][k+1] == false) {
				if(t%2 == 0) {
					q.push({ny, nx, k+1, t+1, moved+1});
					visited[ny][nx][k+1] = true;
				} else {
					q.push({y, x, k, t+1, moved+1});
				}
			} else if(world[ny][nx] == 0 && visited[ny][nx][k] == false) {
				q.push({ny, nx, k, t+1, moved+1});
				visited[ny][nx][k] = true;
			}
		}
	}
	if(ans == INF) ans = -1;
	cout << ans << endl;

	
	
	return 0;
}