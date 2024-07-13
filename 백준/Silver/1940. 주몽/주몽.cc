#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(v[i] + v[j] == m) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}