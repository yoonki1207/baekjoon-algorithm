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

using namespace std;

vector<vector<bool>> bingo, called;
vector<pair<int, int>> coord;

inline void assignNumber(int y, int x) {
	bingo[y][x] = true;
}

bool checkBingo() {
	int nBingo = 0;
	bool isCross = true, isRCross = true;
	for(int i = 0; i < 5; i++) {
		bool isRow = true;
		bool isCol = true;
		for(int j = 0; j < 5; j++) {
			if(bingo[i][j] == false) {
				isRow = false;
			}
			if(bingo[j][i] == false) {
				isCol = false;
			}
		}
		if(isRow) {
			nBingo++;
		}
		if(isCol) {
			nBingo++;
		}
		if(bingo[i][i] == false) {
			isCross = false;
		}
		if(bingo[i][4-i] == false) {
			isRCross = false;
		}
	}
	nBingo += (int)isCross + (int)isRCross;
	return nBingo >= 3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	bingo = vector<vector<bool>>(5, vector<bool>(5));
	coord = vector<pair<int, int>>(26);
	int k = 0, x;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			cin >> x;
			coord[x] = {i, j};
		}
	}
	int ans = 0;
	for(int i = 0; i < 25; i++) {
		cin >> k;
		pair<int, int> c = coord[k];
		assignNumber(c.first, c.second);
		if(ans == 0 && checkBingo()) {
			ans = i+1;
		}
	}
	cout << ans;
	return 0;
}
