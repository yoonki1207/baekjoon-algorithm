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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int s = a+b+c+d;
	vector<int> arr = {
		s-a-b-a-b,
		s-a-c-a-c,
		s-a-d-a-d,
		s-b-c-b-c,
		s-b-d-b-d,
		s-c-d-c-d
	};
	int ans = abs(arr[0]);
	for(int i = 0; i < 6; i++) {
		ans = min(ans, abs(arr[i]));
	}
	cout << ans << endl;
	return 0;
}
