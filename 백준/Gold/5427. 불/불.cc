#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#include <string.h>
#define INF 987654321
#define MAX_N 1001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

const int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int T, w, h;
char building[MAX_N][MAX_N];
bool playerVisited[MAX_N][MAX_N];
bool fireVisited[MAX_N][MAX_N];
queue<pii> player, fire;

inline bool checkRange(int y, int x) {
	return y >= 0 && x >= 0 && y < h && x < w;
}

inline bool canmove(int y, int x) {
	return checkRange(y, x) && building[y][x] == '.';
}

int solve() {
	int cnt = 0;
	while(true) {
		bool moved = false;
		cnt++;
		int len = player.size();
		for(int i = 0; i < len; i++) {
			int y = player.front().first;
			int x = player.front().second;
			player.pop();
			if(building[y][x] != '@') continue;
			for(int j = 0; j < 4; j++) {
				int ny = y+r[j][0];
				int nx = x+r[j][1];
				if(checkRange(ny, nx) == false) return cnt;
				if(canmove(ny, nx) && !playerVisited[ny][nx]) {
					playerVisited[ny][nx] = true;
					building[ny][nx] = '@';
					player.push({ny, nx});
					moved = true;
				}
			}
		}
		len = fire.size();
		for(int i = 0; i < len; i++) {
			int y = fire.front().first;
			int x = fire.front().second;
			fire.pop();
			for(int j = 0; j < 4; j++) {
				int ny = y+r[j][0];
				int nx = x+r[j][1];
				if(checkRange(ny, nx) == false) continue;
				if(!fireVisited[ny][nx] && (canmove(ny, nx) || building[ny][nx] == '@')) {
					fireVisited[ny][nx] = true;
					building[ny][nx] = '*';
					fire.push({ny, nx});
				}
			}
		}
		if(!moved) return -1;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++) {
		memset(playerVisited, false, sizeof(playerVisited));
		memset(fireVisited, false, sizeof(fireVisited));
		while(!player.empty()) player.pop();
		while(!fire.empty()) fire.pop();

		cin >> w >> h;
		string s;
		for(int i = 0; i < h; i++) {
			cin >> s;
			for(int j = 0; j < w; j++) {
				building[i][j] = s[j];
				if(s[j] == '@') {
					player.push({i, j});
					playerVisited[i][j] = true;
				} else if(s[j] == '*') {
					fire.push({i, j});
					fireVisited[i][j] = true;
				}
			}
		}
		int ans = solve();
		if(ans < 0) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << ans << '\n';
		}
	}

	return 0;
}