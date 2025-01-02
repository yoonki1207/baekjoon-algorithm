#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int n, m;
int arr[300][300];
int offset[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void fillAreaWith(int y, int x, int c, int (*brr)[300]) {
	brr[y][x] = c;
	for(int i = 0; i < 4; i++) {
		int offsetY = y + offset[i][0];
		int offsetX = x + offset[i][1];
		if(arr[offsetY][offsetX] && !brr[offsetY][offsetX]) {
			fillAreaWith(offsetY, offsetX, c, brr);
		}
	}
}

int countSide(int y, int x) {
	int ret = 0;
	for(int i = 0; i < 4; i++) {
		int offsetY = y + offset[i][0];
		int offsetX = x + offset[i][1];
		if(arr[offsetY][offsetX] == 0) ret++;
	}
	return ret;
}

int countArea() {
	int c = 1;
	int brr[300][300] = {0};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] && brr[i][j] == 0) {
				fillAreaWith(i, j, c, brr);
				++c;
			}
		}
	}
	return c - 1;
}

bool nextYear() {
	int ret = 0;
	int trr[300][300] = {0};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j]) {
				int sides = countSide(i, j);
				trr[i][j] = max(arr[i][j] - sides, 0);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			ret += arr[i][j] = trr[i][j];
		}
	}
	return (bool)ret;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	int isAreaCalled = false;
	while(nextYear()) {
		ans++;
		if(countArea() >= 2) {
			isAreaCalled = true;
			break;
		}
	}
	ans = isAreaCalled ? ans : 0;
	cout << ans;
	return 0;
}