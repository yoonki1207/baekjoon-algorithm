#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define BLUE_BALL 'B'
#define RED_BALL 'R'
#define HOLE 'O'
#define BLANK '.'
#define WALL '#'
#define MAX_TIMES 10
#define INF 987654321

// Remove the red ball through to the hole.

using namespace std;

int n, m;
int ans = INF;
char board[10][10];

typedef struct coord {
	int x;
	int y;
} coord;

queue<pair<int, pair<coord, coord>>> v;

bool lean_board(int axisx, int axisy) { // axisx is must -1 or 1
	coord red = v.front().second.first;
	coord blue = v.front().second.second;
	int times = v.front().first;

	bool red_removed = false;
	bool blue_removed = false;
	// cout << red.x << ' ' << red.y << ' ' << blue.x << ' ' << blue.y << endl;

	if(red.x*axisx > blue.x*axisx || red.y*axisy > blue.y*axisy) { // move red first
		while(board[red.y + axisy][red.x + axisx] == BLANK) {
			red.x += axisx;
			red.y += axisy;
		}
		if(board[red.y + axisy][red.x + axisx] == HOLE) {
			red_removed = true;
		} else {
			board[red.y][red.x] = RED_BALL;
		}
		while(board[blue.y + axisy][blue.x + axisx] == BLANK) {
			blue.x += axisx;
			blue.y += axisy;
		}
		if(!red_removed) {
			board[red.y][red.x] = BLANK;
		}
		if(board[blue.y + axisy][blue.x + axisx] == HOLE) {
			blue_removed = true;
		}
	} else { // move blue first
		while(board[blue.y + axisy][blue.x + axisx] == BLANK) {
			blue.x += axisx;
			blue.y += axisy;
		}
		if(board[blue.y + axisy][blue.x + axisx] == HOLE) {
			blue_removed = true;
		} else {
			board[blue.y][blue.x] = BLUE_BALL;
		}
		while(board[red.y + axisy][red.x + axisx] == BLANK) {
			red.x += axisx;
			red.y += axisy;
		}
		if(!blue_removed) {
			board[blue.y][blue.x] = BLANK;
		}
		if(board[red.y + axisy][red.x + axisx] == HOLE) {
			red_removed = true;
		}
	}
	if(times+1 < MAX_TIMES && !blue_removed) v.push({times+1, {red, blue}});
	if(red_removed && !blue_removed) ans = min(ans, times + 1);
	// cout << times << endl;
	// if(red_removed) cout << "red removed" << endl;

	// cout << axisx << ", " << axisy << endl;
	// for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < m; j++) {
	// 		if(i == red.y && j == red.x) cout << 'R';
	// 		else if (i == blue.y && j == blue.x) cout << 'B';
	// 		else 
	// 		cout << board[i][j];
	// 	}
	// 	cout << endl;
	// }
	// cout <<endl;
	return red_removed && !blue_removed;
}

bool lean_left() {
	return lean_board(-1, 0);
}

bool lean_right() {
	return lean_board(1, 0);
}

bool lean_up() {
	return lean_board(0, -1);
}

bool lean_down() {
	return lean_board(0, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	coord blue;
	coord red;

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
			if(board[i][j] == RED_BALL) {
				red.x = j;
				red.y = i;
				board[i][j] = BLANK;
			} else if (board[i][j] == BLUE_BALL) {
				blue.x = j;
				blue.y = i;
				board[i][j] = BLANK;
			}
		}
	}
	v.push({0, {red, blue}});
	// int ans = 0;
	while(!v.empty()){
		lean_up();
		lean_right();
		lean_down();
		lean_left();
		v.pop();
		if(ans != INF) break;
	}
	if(ans == INF) ans = -1;
	cout << ans;
	return 0;
}