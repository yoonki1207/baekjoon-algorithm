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

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	int diff1 = p1.second - p1.first;
	int diff2 = p2.second - p2.first;
	return diff1 > diff2;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, A, B;
	cin >> N >> A >> B;
	vector<pair<int, int>> v(N);
	for(int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = {a, b};
	}
	sort(v.begin(), v.end(), cmp);
	lld ans = 0l;
	for(int i = 0; i < A; i++) {
		ans += (lld)v[i].first;
	}
	for(int i = 0; i < B; i++) {
		ans += (lld)v[i+A].second;
	}
	cout << ans << endl;
	return 0;
}