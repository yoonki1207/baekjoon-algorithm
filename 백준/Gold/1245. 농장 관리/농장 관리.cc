#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int arr[101][71];
int n, m;
bool visited[101][71];
int offset[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool isTop(int y, int x) {
	if(visited[y][x] == true) return true;
	bool ret = false;
	visited[y][x] = true;
	for(int i = 0; i < 8; i++) {
		int cy = y + offset[i][0];
		int cx = x + offset[i][1];
		if(cy < 1 || cx < 1 || cy > n || cx > m) continue;
		if(arr[cy][cx] < arr[y][x]) ret = true;
		if(arr[cy][cx] > arr[y][x]) { // 주변부가 더 높으면
			visited[y][x] = false;
			return false;
		}
		if(arr[cy][cx] == arr[y][x] && !isTop(cy, cx)) { // 결국 봉우리가 아니면
			visited[y][x] = false;
			return false;
		}
	}
	return ret;
}

int main() {
	FAST_IO
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(visited[i][j] == false)
				ans += isTop(i, j);
		}
	}
	cout << ans << endl;
	return 0;
}