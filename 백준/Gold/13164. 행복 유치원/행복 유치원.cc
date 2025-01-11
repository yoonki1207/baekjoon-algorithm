#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 2000001
#define lld long long int

using namespace std;

lld arr[300000];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for(int i = 1; i < n; i++) arr[i-1] = arr[i] - arr[i-1];
	sort(arr, arr+n-1, greater<int>());
	lld ans = 0;
	lld summ = 0;
	// for(int i = 0; i < n-1; i++) {
	// 	cout << arr[i] << ' ';
	// }
	for(int i = 0; i < n-1; i++) summ += arr[i];
	for(int i = 0; i < k-1; i++) {
		ans += arr[i];
	}
	cout << summ - ans;
	return 0;
}
/**
1 3 5 6 10
1 3
5 6
10 



 */