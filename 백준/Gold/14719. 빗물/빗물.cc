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
#define MAX_N 1001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int H, W;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> H >> W;
	v = vector<int>(W);
	for(int i = 0; i < W; i++) {
		cin >> v[i];
	}
	int ans = 0;
	for(int i = 1; i <= H; i++) {
		int cnt = 0;
		bool start = false;
		for(int j = 0; j < W; j++) {
			if(v[j] < i) {
				if(start) {
					cnt++;
				}
			} else {
				ans += cnt;
				cnt = 0;
				start = true;
			}
		}	
	}
	cout << ans;
	return 0;
}