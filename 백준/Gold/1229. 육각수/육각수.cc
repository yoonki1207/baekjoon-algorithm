#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321
#define lld long long
#define ull unsigned long long
#define MAX_N 500000

using namespace std;

int n;
vector<int> hexan;
vector<int> dp;
set<int> sets;
int ans = 7;
// int max_i;

void init() {
	hexan.push_back(0);
	hexan.push_back(1);
	sets.insert(1);
	// hexan.push_back(6);
	for(int i = 2; true; i++) {
		int k = i * 4 - 3 + hexan.back();
		if(k>n) break;
		hexan.push_back(k);
		sets.insert(k);
	}
	// cout << hexan.size() << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	init();
	dp = vector<int>(n+1, 7);
	for(int i = 1; i < hexan.size(); i++) {
		dp[hexan[i]] = 1;
	}
	// for(int i = 1; i < 30; i++) {
	// 	cout << dp[i] << ' ';
	// }
	// for(int i = 0; i < hexan.size(); i++) {
	// 	cout << hexan[i] << ' ';
	// }
	if(n == 11 || n == 26) {
		cout << 6;
		return 0;
	}
	if(n <= 130) {
		int ans = 0;
		for(int d = 1; d <= n; d++) {
			for(int i = 1; i < hexan.size(); i++) {
				int x = hexan[i];
				int t = d + x;
				if(t>n) break;
				ans = min(dp[t], dp[d] + 1);
				if(t >= 27 && ans > 5) {
					break;
				}
				dp[t] = ans;
			}
		}
		cout << dp[n];
	} else {
		if(sets.find(n) != sets.end()) {
			cout << 1;
			return 0;
		}
		for(int i = 1; i < hexan.size(); i++) {
			int x = hexan[i];
			if(n-x <= 1) continue;
			if(sets.find(n-x) != sets.end()) {
				cout << 2;	
				return 0;
			}
		}
		for(int i = 1; i < hexan.size(); i++) {
			int a = hexan[i];
			for(int j = 1; j < hexan.size(); j++) {
				int b = hexan[j];
				int t = n - a - b;
				if(t<=0) continue;
				if(sets.find(t) != sets.end()) {
					cout << 3;
					return 0;
				}
			}
		}
		cout << 4;
	}

	
	return 0;
}
