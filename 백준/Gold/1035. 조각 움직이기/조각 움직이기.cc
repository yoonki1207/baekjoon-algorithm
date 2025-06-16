#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321
#define lld long long
#define ull unsigned long long
#define MAX_N 500000

using namespace std;

char arr[5][5];
int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int>> coords;
set<int> visited;

int coordsToBin(const vector<pair<int, int>>& x) {
	int ret = 0;
	for(int i = 0; i < x.size(); i++) {
		int shiftN = x[i].first*5+x[i].second;
		ret |= (1 << shiftN);
	}
	return ret;
}

bool checkRange(int y, int x) {
	return y >= 0 && x >= 0 && y < 5 && x < 5;
}

bool isFinished(vector<pair<int, int>>& x) {
	// cout << "CHECK" << endl;
	int arr[5][5] = {0};
	for(vector<pair<int, int>>::iterator iter = x.begin(); iter != x.end(); iter++) {
		arr[iter->first][iter->second] = 1;
	}
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(arr[i][j] == 1) {
				queue<pair<int, int>> q;
				q.push({i, j});
				arr[i][j] = -1;
				int ret = 1;
				while(!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for(int l = 0; l < 4; l++) {
						int ny = y + r[l][0];
						int nx = x + r[l][1];
						if(checkRange(ny, nx) == false) continue;
						if(arr[ny][nx] == 1) {
							q.push({ny, nx});
							arr[ny][nx] = -1;
							ret++;
						}
					}
				}
				if(ret == coords.size()) return true;
				else return false;
			}
		}
	}
	return false;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	for(int i = 0; i < 5; i++) {
		cin >> s;
		for(int j = 0; j < 5; j++) {
			arr[i][j] = s[j];
			if(s[j] == '*') {
				coords.push_back({i, j});
			}
		}
	}
	queue<pair<int, vector<pair<int, int>>>> q;
	q.push({0, coords});
	visited.insert(coordsToBin(coords));
	int ans = 0;
	while(!q.empty()) {
		vector<pair<int, int>> curr_coords = q.front().second;
		int cnt = q.front().first;
		q.pop();

		if(isFinished(curr_coords)) {
			ans = cnt;
			// cout << endl << coords.size() << endl;
			// for(int i = 0; i < 5; i++) {
			// 	for(int j = 0; j < 5; j++) {
			// 		bool e = false;
			// 		for(int l = 0; l < curr_coords.size(); l++) {
			// 			if(i == curr_coords[l].first && j == curr_coords[l].second) {
			// 				e = true;
			// 			}
			// 		}
			// 		if(e) cout << '*'; else cout << '.';
			// 	}
			// 	cout << endl;
			// }
			break;
		}
		// cout << curr_coords.size() << endl;
		for(vector<pair<int, int>>::iterator iter = curr_coords.begin(); iter != curr_coords.end(); iter++) {
			int y = iter->first;
			int x = iter->second;
			for(int i = 0; i < 4; i++) {
				int ny = y + r[i][0];
				int nx = x + r[i][1];
				if(checkRange(ny, nx) == false) continue;
				vector<pair<int, int>> new_coords = curr_coords;
				new_coords[iter-curr_coords.begin()] = {ny, nx};

				if(visited.find(coordsToBin(new_coords)) != visited.end()) {
					// cout << "FOUND\n";
					continue;
				}
				q.push({cnt+1, new_coords});
				visited.insert(coordsToBin(new_coords));
			}
		}
	}
	cout << ans;

	
	return 0;
}

/*

*....
.*...
..*..
...*.
....*

*/