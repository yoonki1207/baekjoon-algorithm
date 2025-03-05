#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a, b, c;
		int ret = 0;
		cin >> a >> b >> c;
		if(a == b && a == c) {
			ret = 10000 + a * 1000;
		} else if (a == b) {
			ret = 1000 + a * 100;
		} else if (a == c) {
			ret = 1000 + a * 100;
		} else if (b == c) {
			ret = 1000 + b * 100;
		} else {
			ret = max(a, max(b, c))*100;
		}
		ans = max(ans, ret);
	}
	cout << ans;
	
	return 0;
}