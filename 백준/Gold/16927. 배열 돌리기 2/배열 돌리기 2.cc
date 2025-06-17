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

int N, M, R;
int r[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int arr[301][301];

void rotate(int index, int n, int m, int repeat) {
	while(repeat-->0) {
		int y = index;
		int x = index;
		int tmp = arr[index][index];
		int dir = 0;
		int ny = -1, nx = -1;
		while(true) {
			// cout << y << ' ' << x << endl;
			ny = y + r[dir][0];
			nx = x + r[dir][1];
			if(ny < index || nx < index || ny >= index+n || nx >= index+m) {
				dir++;
				dir = dir%4;
				ny = y + r[dir][0];
				nx = x + r[dir][1];
			}
			if(ny == index && nx == index) {
				arr[y][x] = tmp;
				break;
			}
			arr[y][x] = arr[ny][nx];

			y = ny;
			x = nx;
		}
	}
}

void solve() {
	int index = 0;
	int n = N, m = M;
	while(n>=1 && m>=1) {
		int numbers = n*2 + m*2 - 4;
		int repeat = R % numbers;
		rotate(index, n, m, repeat);
		index++;
		n-=2;
		m-=2;
	}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> R;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	solve();

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
