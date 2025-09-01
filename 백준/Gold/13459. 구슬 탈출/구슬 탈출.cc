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
#define MAX_N 1000001
#define lld long long int
#define pii pair<int, int>

#define WALL -1
#define LEFT 0
#define RIGHT 1
#define TOP 2
#define BOTTOM 3

using namespace std;

int R, C;
int arr[10][10];
int r[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // left, right, top, bottom
pii coord_blue, coord_red, coord_hole;
bool visited[10][10][10][10]; // by, bx, ry, rx;

struct Node {
	pii blue;
	pii red;
	int cnt;
};

bool tilt(pii& coord, const pii other, int direction) { // return true if hole in ball
	int cy = coord.first;
	int cx = coord.second;
	int ny = cy + r[direction][0];
	int nx = cx + r[direction][1];
	while(arr[ny][nx] != WALL && !(ny == other.first && nx == other.second)) { // 벽이 아니면서 다른 공이 아니어야함.
		// todo 이동 중 공이 들어가는걸 고려 안함
		cy = ny; cx = nx;
		if(cy == coord_hole.first && cx == coord_hole.second) { // 만약 공이 들어갔다면
			// 다른 공이 들어갈 수 있게 공을 치워줘야함.
			coord.first = -1;
			coord.second = -1;
			return true;
		}
		ny += r[direction][0];
		nx += r[direction][1];
	}
	if(cy == coord_hole.first && cx == coord_hole.second) { // 만약 공이 들어갔다면
		// 다른 공이 들어갈 수 있게 공을 치워줘야함.
		coord.first = -1;
		coord.second = -1;
		return true;
	}
	// 움직인 공의 위치를 조정
	coord.first = cy;
	coord.second = cx;
	return false;
}

bool isRedFirst(pii blue, pii red, int direction) {
	switch (direction)
	{
	case LEFT:
		return red.second < blue.second;
	case RIGHT:
		return red.second > blue.second;
	case TOP:
		return red.first < blue.first;
	case BOTTOM:
		return red.first > blue.first;
	default:
		break;
	}
	return false;
}

void printScreen(pii blue, pii red) {
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			if(i == blue.first && j == blue.second) {
				cout << 'B';
			} else if (i == red.first && j == red.second) {
				cout << 'R';
			} else if (i == coord_hole.first && j == coord_hole.second) {
				cout << 'O';
			} else {
				cout << (arr[i][j] == WALL ? '#' : '.'); 
			}
		}
		cout << '\n';
	}
}

int solve() {
	// queue info: coordination of blue, coordination of red, tilt count
	queue<Node> q;
	int ans = 0;
	q.push({coord_blue, coord_red, 0});
	visited[coord_blue.first][coord_blue.second][coord_red.first][coord_red.second] = true;
	while(!q.empty() && ans == 0) {
		pii blue = q.front().blue;
		pii red = q.front().red;
		int cnt = q.front().cnt;
		// cout << "CNT: " << cnt << endl;
		// printScreen(blue, red);
		// cout << endl;
		q.pop();
		for(int dir = 0; dir < 4; dir++) {
			bool redin, bluein;
			// TODO 방향을 반복하면서 tilt하고, call by reference 매개변수이기 때문에 coord의 복사본을 만들어야한다.
			pii nblue = blue;
			pii nred = red;
			if(isRedFirst(nblue, red, dir)) {
				redin = tilt(nred, nblue, dir);
				bluein = tilt(nblue, nred, dir);
			} else {
				bluein = tilt(nblue, nred, dir);
				redin = tilt(nred, nblue, dir);
			}
			if(!redin && !bluein) {
				if(!visited[nblue.first][nblue.second][nred.first][nred.second] && cnt + 1 < 10) {
					visited[nblue.first][nblue.second][nred.first][nred.second] = true;
					q.push({nblue, nred, cnt+1});
					
				}
			} else if(redin && !bluein) {
				ans = cnt+1;
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	string s;
	cin >> R >> C;
	for(int i = 0; i < R; i++) {
		cin >> s;
		for(int j = 0; j < C; j++) {
			if(s[j] == '#') {
				arr[i][j] = WALL;
			} else if(s[j] == 'R') {
				coord_red = {i, j};
			} else if(s[j] == 'B') {
				coord_blue = {i, j};
			} else if(s[j] == 'O') {
				coord_hole = {i, j};
			}
		}
	}
	int ans = solve();
	// cout << ans << endl;
	cout << (ans==0?0:1) << endl;


	return 0;
}

/*
10 10
##########
#.R......#
##.......#
#O.......#
#........#
#........#
#........#
#........#
#B.......#
##########


10 10
##########
#B#.O.#R.#
####..##.#
#......#.#
#..#.....#
#....#...#
#.#......#
#.....#..#
#........#
##########

10 10
##########
#B#O..#R.#
####..##.#
#......#.#
#..#.....#
#....#...#
#.#......#
#.....#..#
#........#
##########
*/