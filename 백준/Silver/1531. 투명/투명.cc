#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[101][101];


int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int y = y1; y <= y2; y++) {
			for(int x = x1; x <= x2; x++) {
				arr[y][x]++;
			}
		}
	}
	int ans = 0;
	for(int y = 1; y <= 100; y++) {
		for(int x = 1; x<= 100; x++) {
			if(arr[y][x] > m) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}