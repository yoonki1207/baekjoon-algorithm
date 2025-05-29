#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <string>
#define INF 987654321
#define lld long long
#define MAX_N 1000001

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int weight = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x == 1) {
			weight++;
			ans += weight;
		} else {
			weight = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
