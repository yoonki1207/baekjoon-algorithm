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
#define MAX_N 65537
#define lld long long int
#define UP 1
#define LEFT 2

using namespace std;

int R, C, K, W;
int r[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> room;
vector<pair<int, pair<int, int>>> heaters;
vector<vector<int>> walls;
vector<pair<int, int>> inquire;

bool checkRange(int y, int x) {
	return y >= 1 && x >= 1 && y <= R && x <= C;
}

bool inquireTemporature() {
	for(vector<pair<int, int>>::iterator iter = inquire.begin(); iter != inquire.end(); iter++) {
		int y = iter->first;
		int x = iter->second;
		if(room[y][x] < K) return false;
	}
	return true;
}

bool isWallBetween(int y1, int x1, int y2, int x2) { // |(y1,x1) - (y2, x2)| must be 1
	if(checkRange(y1, x1) && checkRange(y2, x2)) {
		if(y1 == y2) {
			int x = max(x1, x2);
			return walls[y1][x] & LEFT;
		} else if(x1 == x2) {
			int y = max(y1, y2);
			return walls[y][x1] & UP;
		}
	} else {
		return false;
	}
	return false;
}

void windRight(int heater_y, int heater_x) {
	vector<vector<bool>> visited;
	visited = vector<vector<bool>>(R+2, vector<bool>(C+2));
	queue<pair<int, pair<int, int>>> q;
	q.push({5, {heater_y, heater_x+1}});
	visited[heater_y][heater_x+1] = true;
	while(!q.empty()) {
		int y = q.front().second.first;
		int x = q.front().second.second;
		int t = q.front().first;
		room[y][x] += t;
		q.pop();
		if(t == 1) continue;
		if(checkRange(y, x+1) && !visited[y][x+1] && !(walls[y][x+1] & LEFT)) {
			q.push({t-1, {y, x+1}});
			visited[y][x+1] = true;
		}
		if(checkRange(y-1, x+1) && !visited[y-1][x+1] && !(walls[y][x] & UP) && !(walls[y-1][x+1] & LEFT)) {
			q.push({t-1, {y-1, x+1}});
			visited[y-1][x+1] = true;
		}
		if(checkRange(y+1, x+1) && !visited[y+1][x+1] && !(walls[y+1][x] & UP) && !(walls[y+1][x+1] & LEFT)) {
			q.push({t-1, {y+1, x+1}});
			visited[y+1][x+1] = true;
		}
	}
}

void windLeft(int heater_y, int heater_x) {
	vector<vector<bool>> visited;
	visited = vector<vector<bool>>(R+2, vector<bool>(C+2));
	queue<pair<int, pair<int, int>>> q;
	q.push({5, {heater_y, heater_x-1}});
	visited[heater_y][heater_x-1] = true;
	while(!q.empty()) {
		int y = q.front().second.first;
		int x = q.front().second.second;
		int t = q.front().first;
		room[y][x] += t;
		q.pop();
		if(t == 1) continue;
		if(checkRange(y, x-1) && !visited[y][x-1] && !(walls[y][x] & LEFT)) {
			q.push({t-1, {y, x-1}});
			visited[y][x-1] = true;
		}
		if(checkRange(y-1, x-1) && !visited[y-1][x-1] && !(walls[y][x] & UP) && !(walls[y-1][x] & LEFT)) {
			q.push({t-1, {y-1, x-1}});
			visited[y-1][x-1] = true;
		}
		if(checkRange(y+1, x-1) && !visited[y+1][x-1] && !(walls[y+1][x] & UP) && !(walls[y+1][x] & LEFT)) {
			q.push({t-1, {y+1, x-1}});
			visited[y+1][x-1] = true;
		}
	}
}

void windUp(int heater_y, int heater_x) {
	vector<vector<bool>> visited;
	visited = vector<vector<bool>>(R+2, vector<bool>(C+2));
	queue<pair<int, pair<int, int>>> q;
	q.push({5, {heater_y-1, heater_x}});
	visited[heater_y-1][heater_x] = true;
	while(!q.empty()) {
		int y = q.front().second.first;
		int x = q.front().second.second;
		int t = q.front().first;
		room[y][x] += t;
		q.pop();
		if(t == 1) continue;
		if(checkRange(y-1, x) && !visited[y-1][x] && !(walls[y][x] & UP)) {
			q.push({t-1, {y-1, x}});
			visited[y-1][x] = true;
		}
		if(checkRange(y-1, x+1) && !visited[y-1][x+1] && !(walls[y][x+1] & UP) && !(walls[y][x+1] & LEFT)) {
			q.push({t-1, {y-1, x+1}});
			visited[y-1][x+1] = true;
		}
		if(checkRange(y-1, x-1) && !visited[y-1][x-1] && !(walls[y][x-1] & UP) && !(walls[y][x] & LEFT)) {
			q.push({t-1, {y-1, x-1}});
			visited[y-1][x-1] = true;
		}
	}
}

void windDown(int heater_y, int heater_x) {
	vector<vector<bool>> visited;
	visited = vector<vector<bool>>(R+2, vector<bool>(C+2));
	queue<pair<int, pair<int, int>>> q;
	q.push({5, {heater_y+1, heater_x}});
	visited[heater_y+1][heater_x] = true;
	while(!q.empty()) {
		int y = q.front().second.first;
		int x = q.front().second.second;
		int t = q.front().first;
		room[y][x] += t;
		q.pop();
		if(t == 1) continue;
		if(checkRange(y+1, x) && !visited[y+1][x] && !(walls[y+1][x] & UP)) {
			q.push({t-1, {y+1, x}});
			visited[y+1][x] = true;
		}
		if(checkRange(y+1, x+1) && !visited[y+1][x+1] && !(walls[y+1][x+1] & UP) && !(walls[y][x+1] & LEFT)) {
			q.push({t-1, {y+1, x+1}});
			visited[y+1][x+1] = true;
		}
		if(checkRange(y+1, x-1) && !visited[y+1][x-1] && !(walls[y+1][x-1] & UP) && !(walls[y][x] & LEFT)) {
			q.push({t-1, {y+1, x-1}});
			visited[y+1][x-1] = true;
		}
	}
}

void windCome() {
	for(vector<pair<int, pair<int, int>>>::iterator iter = heaters.begin(); iter != heaters.end(); iter++) {
		int heater_y = iter->second.first;
		int heater_x = iter->second.second;
		int t = iter->first;
		switch (t)
		{
		case 1:
			windRight(heater_y, heater_x);
			break;
		case 2:
			windLeft(heater_y, heater_x);
			break;
		case 3:
			windUp(heater_y, heater_x);
			break;
		case 4:
			windDown(heater_y, heater_x);
			break;
		default:
			break;
		}
	}
}

void diffusion() {
	vector<vector<int>> tmp;
	tmp = vector<vector<int>>(R+2, vector<int>(C+2));
	for(int i = 1; i <= R; i++) {
		for(int j = 1; j <= C; j++) {
			// if(room[i][j] < 4) continue; // 온도가 낮아 확산 불가
			for(int k = 0; k < 4; k++) {
				int ny = i + r[k][0];
				int nx = j + r[k][1];
				if(isWallBetween(i, j, ny, nx)) continue; // 벽에 막혀있으면 확산 불가
				if(checkRange(ny, nx) && room[i][j] > room[ny][nx]) {
					int diff = (int)((room[i][j]-room[ny][nx]) / 4); 
					tmp[ny][nx] += diff; // 옆으로 확산
					tmp[i][j] -= diff; // 중앙 온도 감소
				}
			}
		}
	}
	for(int i = 1; i <= R; i++) {
		for(int j = 1; j <= C; j++) {
			room[i][j] += tmp[i][j];
		}
	}
}

void decreaseOuterTemperature() {
	for(int i = 1; i <= R; i++) {
		if(room[i][1] > 0) room[i][1]--;
		if(room[i][C] > 0) room[i][C]--;
	}
	for(int j = 2; j < C; j++) {
		if(room[1][j] > 0) room[1][j]--;
		if(room[R][j] > 0) room[R][j]--;
	}
}

void printRoom() {
	for(int i = 1; i <= R; i++) {
		for(int j = 1; j <= C; j++) {
			printf("%3d ", room[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> R >> C >> K;
	room = vector<vector<int>>(R+2, vector<int>(C+2));
	walls = vector<vector<int>>(R+2, vector<int>(C+2));
	int x;
	for(int i = 1; i <= R; i++) {
		for(int j = 1; j <= C; j++) {
			cin >> x;
			if(x == 5) {
				inquire.push_back({i, j});
			} else if(x > 0) {
				heaters.push_back({x, {i, j}});
			}
		}
	}
	int  y, t;
	cin >> W;
	for(int i = 0; i < W; i++) {
		cin >> y >> x >> t;
		if(t == 0) walls[y][x] |= 1;
		else walls[y][x+1] |= 2;
	}

	int ans = 0;
	for(int i = 0; i < 101; i++) {
		windCome();
		diffusion();
		decreaseOuterTemperature();
		++ans;
		if(inquireTemporature()) {
			break;
		}
	}
	cout << ans;


	
	return 0;
}