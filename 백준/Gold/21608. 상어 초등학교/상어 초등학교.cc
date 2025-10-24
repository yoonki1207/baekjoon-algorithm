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
#define lld long long

using namespace std;

const int r[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int N;
vector<int> ordered_student;
vector<vector<int>> liked_mat;
vector<vector<int>> class_mat;

bool checkRange(int y, int x) {
	return y >= 0 && x >= 0 && y < N && x < N;
}

int getNearVal(int y, int x, int student_no) {
	const vector<int>& liked_students = liked_mat[student_no];
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + r[i][0];
		int nx = x + r[i][1];
		if (checkRange(ny, nx) == false) continue;
		int near_no = class_mat[ny][nx];
		for (int j = 0; j < 4; j++) {
			if (near_no == liked_students[j]) {
				ret++;
				break;
			}
		}
	}
	return ret;
}

int getNearEmpty(const int y, const int x) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + r[i][0];
		int nx = x + r[i][1];
		if (checkRange(ny, nx) == false) continue;
		if (class_mat[ny][nx] == 0) ret++;
	}
	return ret;
}

void solve(int student_no) {
	int y = 0, x = 0, val = 0, empty_val = 0;
	vector<pair<int, int>> candidates;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (class_mat[i][j] != 0) continue;
			int res = getNearVal(i, j, student_no);
			if (res > val) {
				val = res;
				empty_val = getNearEmpty(i, j);
				candidates.clear();
				candidates.push_back({ i, j });
			}
			else if (res == val) {
				int nEmpty_val = getNearEmpty(i, j);
				if (empty_val < nEmpty_val) {
					empty_val = nEmpty_val;
					candidates.clear();
				}
				candidates.push_back({ i, j });
			}
		}
	}
	y = candidates[0].first;
	x = candidates[0].second;
	class_mat[y][x] = student_no;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	liked_mat = vector<vector<int>>(N * N + 1, vector<int>(4));
	ordered_student = vector<int>(N * N);
	class_mat = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N * N; i++) {
		cin >> ordered_student[i];
		for (int j = 0; j < 4; j++) {
			cin >> liked_mat[ordered_student[i]][j];
		}
	}
	for (int i = 0; i < ordered_student.size(); i++) {
		solve(ordered_student[i]);
	}

	int satisfied_val = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int val = getNearVal(i, j, class_mat[i][j]);
			satisfied_val += (int)powl(10, val-1);
		}
	}
	cout << satisfied_val << endl;
	
	return 0;
}
