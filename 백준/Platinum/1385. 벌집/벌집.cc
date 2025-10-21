#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#define INF 987654321
#define lld long long

using namespace std;

struct Node {
	int distacne;
	int y;
	int x; 
	pair<int, int> trace;
};

int honeycomb[1200][1200];
int dist[1200][1200];
pair<int, int> trace[1200][1200];

// dir: up, right-up, right-down, down, left-down, left-up
void nextCoord(int &y, int &x, int direction) {
	if (x % 2 == 0) {
		if (direction == 0) {
			--y;
		}
		else if (direction == 1) {
			++x;
		}
		else if (direction == 2) {
			++x;
			++y;
		}
		else if (direction == 3) {
			++y;
		}
		else if (direction == 4) {
			--x;
			++y;
		}
		else {
			--x;
		}
	}
	else {
		if (direction == 0) {
			--y;
		}
		else if (direction == 1) {
			++x;
			--y;
		}
		else if (direction == 2) {
			++x;
		}
		else if (direction == 3) {
			++y;
		}
		else if (direction == 4) {
			--x;
		}
		else {
			--x;
			--y;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x = 1200 / 2, y = 1200 / 2; // 600, 600
	int val = 1;
	int len = 1;
	honeycomb[y][x] = val;

	int a, b;
	int cy = y, cx = x;
	cin >> a >> b;
	while (val <= 1000000) {
		nextCoord(y, x, 0);
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < len; j++) {
				honeycomb[y][x] = ++val;
				if (val == a) {
					cy = y;
					cx = x;
				}
				if (j + 1 < len) {
					nextCoord(y, x, (i+1) % 6);
				}
			}

			if (i != 5)
				nextCoord(y, x, (i + 2) % 6);
		}
		len++;
	}
	memset(dist, -1, sizeof(dist));
	queue<pair<int,int>> q;
	vector<int> t;
	q.push({ cy, cx });
	dist[cy][cx] = 0;
	vector<int> ans;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		if (honeycomb[cy][cx] == b) {
			while (trace[cy][cx].first != 0 && trace[cy][cx].second != 0) {
				if (cy == -1 || cx == -1) break;
				ans.push_back(honeycomb[cy][cx]);
				pair<int, int> next = trace[cy][cx];
				cy = next.first;
				cx = next.second;
			}
			break;
		}
		for (int i = 0; i < 6; i++) {
			int ny = cy;
			int nx = cx;
			nextCoord(ny, nx, i);
			if (honeycomb[ny][nx] == 0) continue;
			if (dist[ny][nx] != -1) continue;
			q.push({ny, nx});
			dist[ny][nx] = dist[cy][cx] + 1;
			trace[ny][nx] = { cy, cx };
		}
	}
	cout << a << ' ';
	while (ans.empty() == false) {
		cout << ans.back() << ' ';
		ans.pop_back();
	}
	return 0;
}
/*


*/