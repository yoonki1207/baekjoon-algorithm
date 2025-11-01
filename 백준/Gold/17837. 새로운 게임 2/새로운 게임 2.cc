#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#define INF 987654321
#define MAX_N 1503
#define lld long long
#define pii pair<int, int>

using namespace std;

// 백준 17837

struct Horse {
	int y;
	int x;
	int index;
	int dir;
};

const int rc[5][2] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

int N, K;
vector<vector<int>> arr;
vector<vector<vector<Horse*>>> board;
vector<Horse*> horses;

void printArr() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << board[i][j].size() << ' ';
		} cout << endl;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	arr = vector<vector<int>>(N+2, vector<int>(N+2, 2));
	board = vector<vector<vector<Horse*>>>(N+2, vector<vector<Horse*>>(N+2));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= K; i++) {
		int r, c, d;
		cin >> r >> c >> d;
		Horse* horse = new Horse(); 
		// struct Horse* horse = (struct Horse*)malloc(sizeof(struct Horse))
		horse->dir = d;
		horse->y = r;
		horse->x = c;
		horse->index = 0;
		horses.push_back(horse);
		board[r][c].push_back(horse);
	}

	int n = 0;
	int ans = 0;
	while (n++ < 1000) {
		for (int horseNumber = 0; horseNumber < horses.size(); horseNumber++) {
			//cout << horseNumber << endl;
			int& dir = horses[horseNumber]->dir;
			int r = horses[horseNumber]->y;
			int c = horses[horseNumber]->x;
			int ny = rc[dir][0] + r;
			int nx = rc[dir][1] + c;
			if (arr[ny][nx] == 1) { // RED
				Horse* horse = horses[horseNumber];
				vector<Horse*>& current = board[r][c];
				vector<Horse*>& next = board[ny][nx];
				int targetIndex = horse->index;
				while (current.size() > 0 && current.back()->index >= targetIndex) {
					current.back()->index = next.size();
					current.back()->y = ny;
					current.back()->x = nx;
					next.push_back(current.back());
					current.pop_back();
				}
				if (next.size() >= 4) ans = n;
			}
			else if (arr[ny][nx] == 2) { // BLUE
				dir = dir <= 2 ? dir == 1 ? 2 : 1 : dir == 3 ? 4 : 3;
				ny = rc[dir][0] + r;
				nx = rc[dir][1] + c;
				if (arr[ny][nx] == 2) continue;
				else {
					horseNumber--;
					continue;
				}
			}
			else {
				Horse* horse = horses[horseNumber];
				vector<Horse*>& current = board[r][c];
				vector<Horse*>& next = board[ny][nx];
				int targetIndex = horse->index;
				int index = horse->index;
				size_t current_size = current.size();
				for (int i = index; i < current_size; i++) {
					current[i]->index = next.size();
					current[i]->y = ny;
					current[i]->x = nx;
					next.push_back(current[i]);
				}
				for (int i = index; i < current_size; i++) {
					current.pop_back();
				}
				if (next.size() >= 4) ans = n;
			}
			if (ans != 0) break;
		}
		if (ans != 0) break;
	}
	cout << (ans != 0 ? ans : -1) << endl;
	return 0;
}