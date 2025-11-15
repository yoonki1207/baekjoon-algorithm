#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#define INF 987654321
#define MAX_N 101
#define lld long long
#define pii pair<int, int>

using namespace std;

int N; // 3
int arr[3];
int dp[MAX_N][MAX_N][MAX_N];
int offset[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 3, 9},
	{1, 9, 3},
};

int ans = 0;

void solve(int a, int b, int c) {

	queue<vector<int>> q;
	q.push({ 0, 0, 0, 0 });
	bool flag = false;
	while (!q.empty() && !flag) {
		vector<int> front = q.front();
		q.pop();
		if (arr[0] <= front[0] &&
			arr[1] <= front[1] &&
			arr[2] <= front[2]) {
			flag = true;
			ans = dp[front[0]][front[1]][front[2]] + 1;
			break;
		}
		for (int i = 0; i < 6 && !flag; i++) {
			int na = front[0] + offset[i][0];
			int nb = front[1] + offset[i][1];
			int nc = front[2] + offset[i][2];
			int tmp_arr[3] = { na, nb, nc };
			sort(tmp_arr, tmp_arr + 3);
			if (dp[tmp_arr[0]][tmp_arr[1]][tmp_arr[2]] == 0) {
				if (tmp_arr[0] >= MAX_N-1 || tmp_arr[1] >= MAX_N-1 || tmp_arr[2] >= MAX_N-1) continue;
				q.push({ tmp_arr[0], tmp_arr[1], tmp_arr[2], front[3] + 1});
				dp[tmp_arr[0]][tmp_arr[1]][tmp_arr[2]] = 
					front[3] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 3);
	//dp[1][3][9] = 1;
	solve(arr[0], arr[1], arr[2]);
	cout << ans - 1;
	return 0;
}
/*
9 3 1 = 1
18 6 2 = 2
18 4 4 = 2
12 12 2
12 4 10
10 6 10
10 12 4



*/