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
using namespace std;

int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<bool>> v;

void press(vector<vector<bool>>& arr, int y, int x) {
	arr[y][x] = !arr[y][x];
	for(int i = 0; i < 4; i++) {
		int ny = y + r[i][0];
		int nx = x + r[i][1];
		if(ny < 0 || nx < 0 || ny >= 10 || nx >= 10) continue;
		arr[ny][nx] = !arr[ny][nx];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	v = vector<vector<bool>>(10, vector<bool>(10));
	for(int i = 0; i < 10; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < 10; j++) {
			v[i][j] = s[j] == 'O';
		}
	}
	int frow = 0;
	int ans = INF;
	for(frow = 0; frow < (1<<10); frow++) {
		int cnt = 0;
		vector<vector<bool>> tmp(v); // constructor copy
		for(int i = 0; i < 10; i++)  {
			if(frow & (1<<i)) {
				press(tmp, 0, i);
				cnt++;
			}
		}
		for(int i = 1; i < 10; i++) {
			for(int j = 0; j < 10; j++) {
				if(tmp[i-1][j]) {
					press(tmp, i, j);
					cnt++;
				}
			}
		}
		bool isClear = true;
		for(int i = 0; i < 10; i++) {
			if(tmp[9][i] == true) isClear = false;
		}
		if(isClear) ans = min(ans, cnt);
	}
	cout << (ans == INF ? -1 : ans);	
	return 0;
}
