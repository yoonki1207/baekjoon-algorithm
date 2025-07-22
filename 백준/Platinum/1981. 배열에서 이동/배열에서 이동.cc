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

using namespace std;

int N;
int arr[100][100];
int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// bool visited[100][100];

bool checkRange(int y, int x) {
	return y >= 0 && x >= 0 && y < N && x < N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	// Input
	cin >> N;
	// Input finish
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int left = 0, right = 200;
	int mid = (left + right) / 2;
	while(left<=right) {
		mid = (left + right) / 2;
		int min_val = 0, max_val = mid;
		bool isPossible = false;

		while(max_val <= 200) { // gap mid에 대해서 모두 탐색
			queue<pair<int, int>> q;
			vector<vector<bool>> visited;
			visited = vector<vector<bool>>(N, vector<bool>(N));

			q.push({0, 0});
			visited[0][0] = true;

			bool isPossilble = (arr[0][0] >= min_val && arr[0][0] <= max_val);

			while(!q.empty() && isPossilble) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				if(y == N-1 && x == N-1) {
					isPossible = true;
				}
				for(int i = 0; i < 4; i++) {
					int ny = y + r[i][0];
					int nx = x + r[i][1];
					if(!checkRange(ny, nx) || visited[ny][nx]) continue;
					if(arr[ny][nx] < min_val || arr[ny][nx] > max_val) {

					} else {
						q.push({ny, nx});
						visited[ny][nx] = true;
					}
				}
			}
			min_val++;
			max_val++;
		}

		if(isPossible) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	cout << left;

	return 0;
}
