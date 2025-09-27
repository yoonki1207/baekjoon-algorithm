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
#define MAX_N 75000
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int H, Y;
int dp[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> H >> Y;
	dp[0] = H;
	for(int i = 1; i <= Y; i++) {
		dp[i] = max((double)dp[i], dp[i-1]*(1.05));
		if(i>=3) dp[i] = max((double)dp[i], dp[i-3]*(1.2));
		if(i>=5) dp[i] = max((double)dp[i], dp[i-5]*(1.35));
	}
	cout << dp[Y];


	return 0;
}