#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001]; // i부터 j까지의 합 = arr[j+1] - arr[i];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		arr[i+1] = arr[i] + x;
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j <= n; j++) {
			if(arr[j] - arr[i] == m) ans++;
		}
	}
	cout << ans;

	return 0;
}