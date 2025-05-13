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
#define MAX_N 1000001

using namespace std;

const int r[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int R, C;
vector<vector<bool>> visited;

bool checkRange(int y, int x) {
	return y >= 0 && x >= 0 && y < R && x < C;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	visited = vector<vector<bool>>(R, vector<bool>(C));

	queue<pair<int, int>> jihoon;
	queue<pair<int, int>> fire;
	
	for(int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < C; j++) {
			if(s[j] == 'J') {
				jihoon.push({i, j});
				visited[i][j] = true;
			}
			else if (s[j] == 'F') {
				fire.push({i, j});
				visited[i][j] = true;
			} else if (s[j] == '#') {
				visited[i][j] = true;
			}
		}
	}
	int ans = 0;
	while(!jihoon.empty()) {
		ans++;
		int jihoonSize = jihoon.size();
		int fireSize = fire.size();
		while(fireSize --> 0) {
			int y = fire.front().first;
			int x = fire.front().second;
			fire.pop();
			for(int i = 0; i < 4; i++) {
				int ny = y + r[i][0];
				int nx = x + r[i][1];
				if(!checkRange(ny, nx) || visited[ny][nx]) continue;
				fire.push({ny, nx});
				visited[ny][nx] = true;
			}
		}
		while(jihoonSize --> 0) {
			int y = jihoon.front().first;
			int x = jihoon.front().second;
			jihoon.pop();
			for(int i = 0; i < 4; i++) {
				int ny = y + r[i][0];
				int nx = x + r[i][1];
				if(!checkRange(ny, nx)) { // escape
					cout << ans << endl;
					return 0;
				} else {
					if(!visited[ny][nx]) {
						jihoon.push({ny, nx});
						visited[ny][nx] = true;
					}
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
		
	return 0;
}
