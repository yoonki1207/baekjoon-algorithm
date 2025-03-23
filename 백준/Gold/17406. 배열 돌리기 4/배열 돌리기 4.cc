#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int N, M, K;
vector<vector<int>> arr;
vector<pair<int, pair<int, int>>> cmds;
int r[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void singleRotate(int _y, int _x, int _s, vector<vector<int>>& v) {
	int tmp = v[_y][_x];
	int y = _y;
	int x = _x;
	int cnt = 0;
	int d = 0;
	while(d < 4) {
		int ny = y + r[d][0];
		int nx = x + r[d][1];
		if(ny - _y >= _s || nx - _x >= _s || nx < _x || ny < _y) {
			d++;
		} else {
			v[y][x] = v[ny][nx];
			y = ny;
			x = nx;
		}
	}
	v[_y][_x+1] = tmp;
}

void rotate(int r, int c, int s, vector<vector<int>>& v) {
	for(int i = 1; i <= s; i++) {
		singleRotate(r-i-1, c-i-1,1+i*2, v);
	}
}

int getMin(vector<vector<int>> v) {
	vector<int> ret(N, 0);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			ret[i] += v[i][j];
		}
	}
	int m = INF;
	for(int i = 0; i < N; i++) m = min(m, ret[i]);
	return m;
}

int solution() {
	int ans = INF;
	sort(cmds.begin(), cmds.end());
	do {
		vector<vector<int>> v = arr;
		for(int i = 0; i < cmds.size(); i++) {
			int a = cmds[i].first;
			int b = cmds[i].second.first;
			int c = cmds[i].second.second;
			rotate(a, b, c, v);
		}
		int res = getMin(v);
		ans = min(ans, res);
	} while(next_permutation(cmds.begin(), cmds.end()));
	return ans;;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 

	cin >> N >> M >> K;
	arr = vector<vector<int>>(N, vector<int>(M, 0));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cmds.push_back({a, {b, c}});
	}
	cout << solution() << endl;
	return 0;
}