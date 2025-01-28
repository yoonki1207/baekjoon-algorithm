#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#define INF 987654321
#define lld long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int arr[401][401];
int n, k;
/*
. 0 0 .
. . 0 0
. . . 0
. . . .

*/

void floydWashall() {
	for(int transit = 1; transit <= n; transit++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j || i == transit || j == transit) continue;
				if(arr[i][j] > arr[i][transit] + arr[transit][j]) {
					arr[i][j] = arr[i][transit] + arr[transit][j];
				}
			}
		}
	}
}

int main() {
	FAST_IO
	cin >> n >> k;
	for(int i = 0; i < 401; i++) for(int j = 0; j < 401; j++) arr[i][j] = INF;
	for(int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 0;
	}
	floydWashall();
	int T;
	cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case) {
		int a, b;
		cin >> a >> b;
		bool forward = arr[a][b] == 0;
		bool backward = arr[b][a] == 0;
		int ans = 0;
		if(forward) ans = -1;
		else if (backward) ans = 1;
		cout << ans << '\n';
	}
	return 0;
}