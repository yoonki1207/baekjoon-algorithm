#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int n;
int arr[21][21];
int district[21][21];

//d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N
bool isValid(int x, int y, int d1, int d2) {
	return x+d1+d2<=n && 1<=y-d1 && y+d2<=n;
}

bool makeDirstrict(int x, int y, int d1, int d2) {
	if(!isValid(x, y, d1, d2)) return false;
	for(int r = 1; r <= n; r++) {
		for(int c = 1; c <= n; c++) {
			int num = 0;
			if(c <= y && r < x + d1 && c + r < x + y) {
				num = 1;
			} else if(y < c && r <= x + d2 && c - r > y - x) {
				num = 2;
			} else if (c < y - d1 + d2 && x + d1 <= r && c - r < y - x - d1*2) {
				num = 3;
			} else if(y - d1 + d2 <= c && x + d2 < r && r + c > x + y + d2*2) {
				num = 4;
			} else {
				num = 5;
			}

			district[r][c] = num;
		}
	}
	return true;
}

int getDiff() {
	int population[6] = {0};
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j<= n; j++) {
			int num = district[i][j];
			population[num] += arr[i][j];
		}
	}
	int min_p = INF, max_p = 0;
	for(int i = 1; i <= 5; i++) {
		min_p = min(min_p, population[i]);
		max_p = max(max_p, population[i]);
	}
	return max_p - min_p;
}

void printDistrict() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << district[i][j] << ' ';
		}cout << endl;
	}
}

void Input() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
}

void solution() {
	int ans = INF;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int d1 = 1; d1 <= n; d1++) {
				for(int d2 = 1; d2 <= n; d2++) {
					bool valid = makeDirstrict(i, j, d1, d2);
					if(valid) {
						int diff = getDiff();
						ans = min(ans, diff);
					}
				}
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// n = 7;
	// makeDirstrict(2, 4, 2, 2);
	// printDistrict();
	// cout << endl;
	// makeDirstrict(2, 5, 3, 2);
	// printDistrict();
	// cout << endl;
	// makeDirstrict(4, 3, 1, 1);
	// printDistrict();
	// cout << endl;
	Input();
	solution();
	
	return 0;
}
