#include <iostream>
#include <algorithm>

using namespace std;

int n, h, w;

int main(int argc,char* argv[]) {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> h >> w;
	int ans = 0;
	for(int i = 0; i < n/2; i++) {
		int a, b; cin >> a >> b;
		int s = min(a, w-b);
		int e = max(a+w, w*2-b);
		int k = 2*w*h - (e-s)*h;
		ans += k;
	}
	cout << ans;
	return 0;
}