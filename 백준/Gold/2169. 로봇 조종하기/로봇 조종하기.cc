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
#define PRN cout << "DEBUG" << endl

using namespace std;

int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> mars, isum, arr; // isum: interval-sum

int N, M;

int intervalSum(int row, int a, int b) {
	int left = min(a, b);
	int right = max(a, b);
	return isum[row][right+1]-isum[row][left];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> N >> M;
	mars = vector<vector<int>>(N, vector<int>(M));
	isum = vector<vector<int>>(N, vector<int>(M+1));
	arr = vector<vector<int>>(N, vector<int>(M));

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> mars[i][j];
			isum[i][j+1] += isum[i][j] + mars[i][j];
		}
	}

	// for(int row = N-1; row >= 0; row--) { // 1,000,000,000
	// 	for(int col = 0; col < M; col++) {
	// 		if(row == N-1) {
	// 			arr[row][col] = intervalSum(row, col, M-1);
	// 		} else {
	// 			for(int down = 0; down < M; down++) {
	// 				arr[row][col] = max(arr[row][col], intervalSum(row, col, down) + arr[row+1][down]);
	// 			}
	// 		}
	// 	}
	// }
	for(int i = 0; i < N; i++) {
		if(i == 0) {
			for(int j = 0; j < M; j++) {
				if(j == 0) arr[i][j] = mars[i][j];
				else arr[i][j] += arr[i][j-1] + mars[i][j];
			}
		} else {
			vector<int> tmplr(M);
			vector<int> tmprl(M);
			for(int j = 0; j < M; j++) {
				if(j == 0) {
					tmplr[j] = arr[i-1][j] + mars[i][j];
					tmprl[M-j-1] = arr[i-1][M-j-1] + mars[i][M-j-1];
				}
				else {
					tmplr[j] = max(tmplr[j-1] + mars[i][j], arr[i-1][j] + mars[i][j]);
					tmprl[M-j-1] = max(tmprl[M-j] + mars[i][M-j-1], arr[i-1][M-j-1] + mars[i][M-j-1]);
				}
			}
			for(int j = 0; j < M; j++) {
				arr[i][j] = max(tmplr[j], tmprl[j]);
			}
		}
	}
	// for(int i = 0; i < N; i++) {
	// 	for(int j = 0; j <M; j++) {
	// 		cout << arr[i][j] << ' ';
	// 	}cout << endl;
	// }
	cout << arr[N-1][M-1];
	return 0;
}