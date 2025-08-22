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
#define MAX_N 100000
#define lld long long int
using namespace std;

vector<int> dice(11);
int score[500];

int move(int& pos, int n) {
	if(pos >= 21 && pos < 100) return -1;
	int ret = 0;
	if(pos < 100) {
		if(pos == 5) {
			pos = 100;
		} else if(pos == 10) {
			pos = 200;
		} else if(pos == 15) {
			pos = 300;
		} else {
			pos += n;
			if(pos > 20) { // finished
				pos = 21;
				return 0;
			}
		}
	}
	if(pos < 100) {
		return score[pos];
	}
	if(pos < 200) {
		if(pos + n > 103) {
			pos = 400 + (n - 104 + pos);
		} else {
			pos += n;
		}
	} else if(pos < 300) {
		if(pos + n > 202) {
			pos = 400 + (n - 203 + pos);
		} else {
			pos += n;
		}
	} else if(pos < 400) {
		if(pos + n > 303) {
			pos = 400 + (n - 304 + pos);
		} else {
			pos += n;
		}
	} else if(pos < 500) {
		if(pos + n == 403) {
			pos = 20;
			return score[pos];
		} else if(pos + n > 403) {
			pos = 21;
			return 0;
		} else {
			pos += n;
		}
	}
	return score[pos];
}

vector<int> horses(4);
int ans = -1;

int dfs(int index, int sum) {
	if(index > 10) {
		ans = max(ans, sum);
		return 0;
	}
	int n = dice[index];
	// if(index >= 10) cout << n << endl;
	int continue_count = 0;
	for(int i = 0; i < horses.size(); i++) {
		int pos = horses[i];
		int score = move(pos, n);
		// if(score <= 0) continue;
		// 만약 말이 겹치면
		if(score > 0 && (horses[0] == pos || horses[1] == pos || horses[2] == pos || horses[3] == pos)) {
			continue_count++;
			continue;
		} else { // 안겹치면
			int prev_pos = horses[i];
			horses[i] = pos;
			dfs(index + 1, sum + score);
			horses[i] = prev_pos;
		}
	}
	if(continue_count == 4) {
		ans = max(ans, sum);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	for(int i = 1; i <= 20; i++) {
		score[i] = i*2;
	}
	score[101] = 13; score[102] = 16; score[103] = 19;
	score[201] = 22; score[202] = 24;
	score[301] = 28; score[302] = 27; score[303] = 26;
	score[400] = 25; score[401] = 30; score[402] = 35;


	for(int i = 0; i < dice.size(); i++) {
		cin >> dice[i];
	}
	dfs(0, 0);
	cout << ans << endl;


	return 0;
}