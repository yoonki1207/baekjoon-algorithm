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

int N;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	v = vector<int>(N);
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		v[i] = x;
	}
	sort(v.begin(), v.end());
	int ans = 1;
	if(v[0] != 1) {
		cout << ans;
		return 0;
	}
	for(int i = 1; i < N; i++) {
		int l = v[i];
		int r = ans + v[i];
		if(ans < l-1) {
			cout << ans + 1;
			return 0;
		} else {
			ans = r;
		}
	}
	cout << ans + 1;
		
	return 0;
}