#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <string>
#define INF 987654321
#define lld long long
#define ull unsigned long long
#define MAX_N 1000001

using namespace std;

int K, W, H;
vector<vector<int>> v;
vector<vector<vector<int>>> cache;

int nr[12][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};


bool checkRange(int y, int x) {
	return y >= 0 && x >= 0 && y < H && x < W;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> K >> W >> H;
	v = vector<vector<int>>(H, vector<int>(W));
	cache = vector<vector<vector<int>>>(H, vector<vector<int>>(W, vector<int>(31, INF)));
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			cin >> v[i][j];
		}
	}

	int ans = -1;
	// y, x, k, c
	queue<pair<int, pair<int, pair<int, int>>>> q;
	q.push({0, {K, {0, 0}}});
	while(!q.empty()) {
		int y = q.front().second.second.first;
		int x = q.front().second.second.second;
		int k = q.front().second.first;
		int c = q.front().first;
		q.pop();
		if(y == H-1 && x == W-1) {
			ans = ans == -1 ? c: min(ans, c);
			break;
		}
		if(c >= cache[y][x][k]) continue;
		cache[y][x][k] = c;
		
		for(int i = 0; i < 12; i++) {
			int ny = y + nr[i][0];
			int nx = x + nr[i][1];
			if(checkRange(ny, nx) == false || v[ny][nx] == 1) continue;
			if(i < 4) {
				q.push({c+1, {k, {ny, nx}}});
			} else if(k > 0) {
				q.push({c+1, {k-1, {ny, nx}}});
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}

/*
1
4 3
0 0 1 0
0 0 1 0
0 0 1 0
*/