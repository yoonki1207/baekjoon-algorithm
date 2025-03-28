#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int M, N, K;
int arr[100][100];
int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int getArea(int y, int x) {
	int ret = 1;
	arr[y][x] = 1;
	for(int i = 0; i < 4; i++) {
		int ny = y + r[i][0];
		int nx = x + r[i][1];
		if(ny < 0 || nx < 0 || ny >= M || nx >= N || arr[ny][nx] == 1) continue;
		ret += getArea(ny, nx);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> M >> N >> K;
	for(int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int i = y1; i < y2; i++) {
			for(int j = x1; j < x2; j++) {
				arr[i][j] = 1;
			}
		}
	}
	vector<int> v;
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			if(arr[i][j] == 0) {
				int s = getArea(i, j);
				v.push_back(s);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for(auto i: v) {
		cout << i << ' ';
	}
	
	return 0;
}