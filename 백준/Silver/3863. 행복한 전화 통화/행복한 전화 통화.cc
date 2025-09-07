#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#include <string.h>
#define INF 987654321
#define MAX_N 800000
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int n, w;
int cache1[MAX_N], cache2[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n, m, source, destination, left, right, ans;
	while(true) {
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		vector<int> start(n), duration(n);
		for(int i = 0; i < n; i++) {
			cin >> left >> right >> start[i] >> duration[i];
		}
		for(int i = 0; i < m; i++) {
			ans = 0;
			cin >> left >> right;
			right += left;
			for(int j = 0; j < n; j++) {
				if(!((right <= start[j]) || (left >= duration[j]+start[j]))) {
					ans++;
					// cout << left << ' ' << right << ' ' << start[j] << ' ' << duration[j] << endl;
					// cout << (right < start[j]) << ' ' << (right < start[j]+duration[j]) << ' ' << (left > start[j]) << ' ' << (left > duration[j]+start[j]) << endl;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
