#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int L;
vector<vector<int>> answer;
vector<vector<int>> panels[5];
pair<int, int> coords[5];
vector<pair<int, int>> size_array(5);

inline bool checkRange(int y, int x) {
	return x >= 0 && y >= 0 && x < L && y < L;
}

bool canBatch(int panel_id, int y, int x, vector<vector<int>>& board) {
	vector<vector<int>>& panel = panels[panel_id];
	int n = panel.size(), m = panel[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ny = i + y;
			int nx = j + x;
			if (panel[i][j] == 0) continue;
			if (!checkRange(ny, nx) || board[ny][nx] != 0) return false;
		}
	}
	return true;
}

void batch(int panel_id, int y, int x, vector<vector<int>>& board, int val) {
	vector<vector<int>>& panel = panels[panel_id];
	int n = panel.size(), m = panel[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int ny = y + i;
			int nx = x + j;
			if (panel[i][j] == 0) continue;
			board[ny][nx] = val;
		}
	}
}

void printPanel(vector<vector<int>>& board) {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}

void updatePanel(const vector<vector<int>>& board) {
	bool isUpdateable = false;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			if (board[i][j] < answer[i][j]) {
				isUpdateable = true;
				break;
			}
			else if (board[i][j] > answer[i][j]) {
				return;
			}
		}
		if (isUpdateable) break;
	}
	if (isUpdateable) {
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < L; j++) {
				answer[i][j] = board[i][j];
			}
		}
	}
}

void batchPanel(int id, vector<vector<int>>& board) {
	if (id == 5) {
		// TODO
		//printPanel(board);
		updatePanel(board);
		return;
	}
	int panel_id = size_array[id].second;
	vector<vector<int>>& panel = panels[panel_id];
	int n = panel.size(), m = panel[0].size();
	for (int y = 0; y < L - n + 1; y++) {
		for (int x = 0; x < L - m + 1; x++) {
			if (canBatch(panel_id, y, x, board)) {
				batch(panel_id, y, x, board, panel_id + 1);
				batchPanel(id + 1, board);
				batch(panel_id, y, x, board, 0);
			}
		}
	}
}

bool customCompare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> L;
	answer = vector<vector<int>>(L, vector<int>(L, 9));
	for (int i = 0; i < 5; i++) {
		size_array[i].second = i;
		cin >> n >> m;
		panels[i] = vector<vector<int>>(n, vector<int>(m));
		for (int j = 0; j < n; j++) {
			string s;
			cin >> s;
			for (int k = 0; k < m; k++) {
				panels[i][j][k] = (s[k] == '#' ? i + 1 : 0);
				if (panels[i][j][k]) size_array[i].first++;
			}
		}
	}
	sort(size_array.begin(), size_array.end(), customCompare);
	int summ = 0;
	for (int i = 0; i < 5; i++) {
		//cout << size_array[i].first << ' ' << size_array[i].second << endl;
		summ += size_array[i].first;
	}
	if (summ != L * L) {
		cout << "gg\n";
		return 0;
	}

	// print panels
	/*for (int i = 0; i < 5; i++) {
		for (int j = 0; j < panels[i].size(); j++) {
			for (int k = 0; k < panels[i][j].size(); k++) {
				cout << panels[i][j][k];
			} cout << endl;
		}
		cout << endl;
	}*/
	vector<vector<int>> board(L, vector<int>(L));
	batchPanel(0, board);
	//solve(4, board, false);
	/*int pid = 1;
	while (getNextCoord(pid)) {
		cout << coords[pid].first << ' ' << coords[pid].second << endl;
	}*/
	if (answer[0][0] == 9) {
		cout << "gg\n";
	}
	else {
		printPanel(answer);
	}

	return 0;
}

/*
이분 매칭 idea.

5번 패널을 최전방에 배치한다.
4번 패널을 최전방에 배치한다.
만약 다른 패널 때문에 배치하지 못 하면, 이미 배치되어있는 패널을 옮긴다.

10
1 1
#
1 1
#
10 10
##########
##########
##########
##########
##########
##########
##########
##########
##########
######....
1 1
#
1 1
#

*/