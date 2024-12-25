#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1500001][2];
int dp[1500001];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for(int i = n-1; i >= 0; i--) {
		int index = i + arr[i][0];
		if(index <= n) {
			dp[i] = max(dp[index] + arr[i][1], dp[i+1]);
		} else {
			dp[i] = dp[i+1];
		}
		// dp[i] = i에서의 최대로 벌 수 있는 값. = max(i번째 상담을 했을 때 최대로 벌 수 있는 값, i번째 상담을 안했을 때 최대로 벌 수 있는 값)
	}
	cout << dp[0] << endl;
	return 0;
}