#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#define INF 987654321
#define lld long long

using namespace std;

int n;
vector<int> arr;
lld dp[101][21];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	arr = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0][arr[0]] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int k = 0; k <= 20; k++) {
			if (k - arr[i] >= 0) {
				dp[i][k] += dp[i - 1][k - arr[i]];
			}
			if (k + arr[i] <= 20) {
				dp[i][k] += dp[i - 1][k + arr[i]];
			}
		}
	}
	
	cout << dp[n-2][arr[n - 1]];
	return 0;
}
/*
3 + 3 - 3 = 3
3 - 3 + 3 = 3

6 - 3 = 3
0 + 3 = 3

=> 마지막 숫자가 -3인 경우, 이전 숫자들이 6을 만들 경우의 수를 구한다.
=> 마지막 숫자가 +3일 경우, 이전 숫자들이 0을 만들 경우의 수를 구한다.

좀 더 일반화해서

마지막 숫자가 n인 경우, 이전 숫자들이 k를 만들 경우의 수를 모두 구하고, n+k 혹은
n - k에 대해서 dp를 업데이트 해준다.


8 3 2 4 8 7 2 4 0 8 = 8

8을 만드는 가짓수 = 0을 만드는 방법 가짓수 + 16을 만드는 방법 가짓수.


*/
