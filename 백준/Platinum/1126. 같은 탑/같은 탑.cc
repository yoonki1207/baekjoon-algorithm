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
#define MAX_N 250000
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int N;
int dp[2][MAX_N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >> N;
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	int i = 0, h = 0, val;
	while(N--) {
		cin >> h;
		int ni = i^1;
		for(int j = 0; j <= MAX_N; j++) {
			if((val = dp[i][j]) >= 0) {
				int a = j+h, b = abs(j-h);
				dp[ni][j] = max(dp[ni][j], dp[i][j]); // 블럭을 사용하지 않은 경우
				if(a <= MAX_N) dp[ni][a] = max(dp[ni][a], val+h);
				if(b <= MAX_N) dp[ni][b] = max(dp[ni][b], val+(j < h ? b : 0));
			}
		}
		i = ni;
	}
	cout << (dp[i][0] > 0 ? dp[i][0] : -1);

	return 0;
}
