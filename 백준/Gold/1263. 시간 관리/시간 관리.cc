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

int N;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	v = vector<pair<int, int>>(N);
	for(int i = 0; i < N; i++) {
		int t, s;
		cin >> t >> s;
		v[i] = {s, t};
	}

	sort(v.begin(), v.end());
	int ans = INF;
	int prev = 0;
	for(int i = 0; i < v.size(); i++) {
		int gap = v[i].first - (prev + v[i].second);
		ans = min(ans, gap);
		prev += v[i].second;
	}
	cout << (ans < 0 ? -1 : ans);
	return 0;
}
