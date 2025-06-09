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
#define ull unsigned long long
#define MAX_N 500000

using namespace std;

int X, K;
int cache[2][MAX_N+1];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> X >> K;

	queue<pair<int, int>> q;
	int ans = -1;
	cache[0][X] = 1;
	q.push({0, X});
	int i = 0;
	while(!q.empty()) {
		int t = q.front().first;
		int x = q.front().second;
		int k = K + t*(t+1)/2;
		q.pop();

		if(k > MAX_N) {
			break;
		}

		if(cache[t%2][k] == 1) {
			ans = t;
			break;
		}
		
		if(x>0 && cache[(t+1)%2][x-1] == 0) {
			cache[(t+1)%2][x-1] = 1;
			q.push({t+1, x-1});
		}
		if(x<MAX_N && cache[(t+1)%2][x+1] == 0) {
			cache[(t+1)%2][x+1] = 1;
			q.push({t+1, x+1});
		}
		if(x*2<=MAX_N && cache[(t+1)%2][x*2] == 0) {
			cache[(t+1)%2][x*2] = 1;
			q.push({t+1, x*2});
		}

	}
	cout << ans << endl;
	return 0;
}
