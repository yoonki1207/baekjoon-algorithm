#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#define INF 987654321
#define lld long long

using namespace std;

int R, C;
int arr[750][750];
int dp1[750][750]; // / - right-up
int dp2[750][750]; // \   left-up

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			arr[i][j] = s[j] == '0' ? 0 : 1;
			if (j + 1 < C && i - 1 >= 0) {
				dp1[i][j] = arr[i][j] == 0 ? 0 : dp1[i - 1][j + 1] + 1;
			}
			else {
				dp1[i][j] = arr[i][j];
			}
			if (j - 1 >= 0 && i - 1 >= 0) {
				dp2[i][j] = arr[i][j] == 0 ? 0 : dp2[i - 1][j - 1] + 1;
			}
			else {
				dp2[i][j] = arr[i][j];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (dp1[i][j] > ans) {
				int max_len = dp1[i][j];
				while (max_len > ans) {
					if (i + max_len - 1 < R && j + max_len - 1 < C && max_len*2 - 2 < C) {
						bool isPossible =
							dp1[i + max_len - 1][j + max_len - 1] >= max_len &&
							dp2[i + max_len - 1][j + max_len - 1] >= max_len &&
							dp2[i][j + max_len*2 - 2] >= max_len;
						if (isPossible) {
							ans = max_len;
							break;
						}
					}
					max_len--;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
/*
5 5
00100
01010
10101
01000
00100


*/