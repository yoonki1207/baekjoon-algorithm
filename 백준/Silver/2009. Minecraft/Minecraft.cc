#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 2000001

using namespace std;

int arr[3][100][100];
int brr[100][100][100];
int n;

bool isValid() {
	int trr[3][100][100] = {0};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(brr[i][j][k]) {
					trr[0][j][k] = 1;
					trr[1][i][k] = 1;
					trr[2][i][j] = 1;
				}
			}
		}
	}
	// bool isValid = true;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(arr[i][j][k] != trr[i][j][k]) {
					return false;
				}
			}
		}
	}
	return true;
}

void solve() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(arr[0][j][k]) {
					brr[i][j][k] += 1;
				} else {
					brr[i][j][k] = 0;
				}
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(arr[1][i][k]) {
					brr[i][j][k] += 1;
				} else {
					brr[i][j][k] = 0;
				}
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(arr[2][i][j]) {
					brr[i][j][k] += 1;
				} else {
					brr[i][j][k] = 0;
				}
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(brr[i][j][k] == 3) brr[i][j][k] = 1;
				else brr[i][j][k] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < n; j++) {
			string s;
			cin >> s;
			for(int k = 0; k < n; k++) {
				arr[i][j][k] = (int)(s[k] == '1');
			}
		}
	}

	solve();
	if(isValid()) {
		cout << "YES\n";
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n; k++) {
					cout << brr[i][j][k];
				}cout << '\n';
			}
		}
	} else {
		cout << "NO";
	}
	
	return 0;
}
