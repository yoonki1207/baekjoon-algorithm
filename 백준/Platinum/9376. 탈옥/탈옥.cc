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
#define MAX_N 102
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

#define WALL -1
#define DOOR 1
#define PRISONER 2

using namespace std;

const int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<int>> prison;
int T, R, C;
string s;

vector<vector<int>> dijkstra(int start_y, int start_x) {
	vector<vector<int>> dist;
	dist = vector<vector<int>>(R+2, vector<int>(C+2, INF));
	dist[start_y][start_x] = 0;
	priority_queue<pair<int, pair<int, int>>> pq; // distance, y, x
	pq.push({0, {start_y, start_x}});
	while(!pq.empty()) {
		int d = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		for(int i = 0; i < 4; i++) {
			int ny = y + r[i][0];
			int nx = x + r[i][1];
			int door = 0;
			if(ny < 0 || nx < 0 || ny >= R+2 || nx >= C+2 || prison[ny][nx] == WALL) continue;
			if(prison[ny][nx] == DOOR) {
				door = 1;
			}
			if(dist[ny][nx] == INF || dist[ny][nx] > d + door) {
				dist[ny][nx] = d + door;
				pq.push({-dist[ny][nx], {ny, nx}});
			}
		}
	}
	return dist;
}

int getCode(char c) {
	switch (c)
	{
	case '*': return -1;
	case '#': return 1;
	case '$': return 2;
	default: return 0;
	}
}

void printDist(vector<vector<int>> dist) {
	for(int i = 0; i < dist.size(); i++) {
		for(int j = 0; j < dist[i].size(); j++) {
			if(dist[i][j] != INF)
			cout << dist[i][j] << ' ';
			else cout << "* ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++) {
		vector<pair<int, int>> prisoners;
		cin >> R >> C;
		prison = vector<vector<int>>(R+2, vector<int>(C+2, 0));
		for(int i = 0; i < R; i++) {
			cin >> s;
			for(int j = 0; j < C; j++) {
				prison[i+1][j+1] = getCode(s[j]);
				if(prison[i+1][j+1] == PRISONER) {
					prisoners.push_back({i+1, j+1});
				}
			}
		}
		vector<vector<int>> dist1 = dijkstra(0, 0);
		vector<vector<int>> dist2 = dijkstra(prisoners[0].first, prisoners[0].second);
		vector<vector<int>> dist3 = dijkstra(prisoners[1].first, prisoners[1].second);
		vector<vector<int>> dist;
		dist = vector<vector<int>>(R+2, vector<int>(C+2, 0));
		int ans = INF;
		for(int i = 0; i < R+2; i++) {
			for(int j = 0; j < C+2; j++) {
				if(prison[i][j] == WALL || dist1[i][j] == INF || dist2[i][j] == INF || dist3[i][j] == INF) {
					dist[i][j] = INF;
					continue;
				}
				dist[i][j] += dist1[i][j] + dist2[i][j] + dist3[i][j];
				if(prison[i][j] == DOOR) {
					dist[i][j] -=2;
				}
				ans = min(ans, dist[i][j]);
			}
		}
		// printDist(dist);
		cout << ans << '\n';
	}
	
	return 0;
}
