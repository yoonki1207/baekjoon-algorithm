#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321

using namespace std;

string a, b, c;
int dp[101][101][101];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> c;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			for (int k = 0; k < c.size(); k++) {
				if (a[i] == b[j] && a[i] == c[k]) {
					dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
				}
				else {
					dp[i + 1][j + 1][k + 1] = max(dp[i][j + 1][k + 1],
						max(dp[i + 1][j][k + 1], dp[i + 1][j + 1][k]));
				}
			}
		}
	}
	cout << dp[a.size()][b.size()][c.size()];
	return 0;
}