#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int N, M;
int arr[50][50];
int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool checkRange(int y, int x) {
	return y >= 0 && x >= 0 && y < N && x < M;
}

int getMax(int y, int x) {
	int ret = 0;
	queue<pair<int, pair<int, int>>> q;
	vector<vector<int>> v(N, vector<int>(M, -1));
	q.push({0, {y, x}});
	v[y][x] = 0;
	while(!q.empty()) {
		int d = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int ny = y + r[i][0];
			int nx = x + r[i][1];
			if(!checkRange(ny, nx)) continue;
			if(arr[ny][nx] < 0 && v[ny][nx] < 0) {
				v[ny][nx] = d+1;
				ret = max(ret, d+1);
				q.push({d+1, {ny, nx}});
			}
		}
	}
	return ret;
}

int solution() {
	int ret = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(arr[i][j] < 0) {
				ret = max(ret, getMax(i, j));
			}
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		string s; cin >> s;
		for(int j = 0; j < M; j++) {
			if(s[j] == 'L') {
				arr[i][j] = -1;
			}
		}
	}
	cout << solution() << endl;
	return 0;
}