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

int N;
vector<pii> v;

inline int get_dist(pii a, pii b) {
	int x = b.first - a.first;
	int y = b.second - a.second;
	return x*x + y*y;
}

int solve(int start, int end) {
	if(start == end) return INF;
	if(end - start == 1) return get_dist(v[start], v[end]);
	int mid = (start + end) / 2;
	int min_dist = min(solve(start, mid), solve(mid+1, end));
	vector<pii> middles;
	for(int index = start; index <= end; index++) {
		if((v[index].first - v[mid].first)*(v[index].first - v[mid].first) < min_dist) {
			middles.push_back({v[index].second, v[index].first});
		}
	}
	sort(middles.begin(), middles.end());
	for(int i = 0; i < middles.size(); i++) {
		for(int j = i+1; j < middles.size(); j++) {
			if(middles[j].first - middles[i].first >= min_dist) {
				break;
			}
			min_dist = min(min_dist, get_dist(middles[i], middles[j]));
		}
	}
	return min_dist;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int x, y, min_dist = INF;
	cin >> N;
	v = vector<pii>(N);
	for(int i = 0; i < N; i++) {
		cin >> x >> y;
		v[i] = {x, y};
	}
	sort(v.begin(), v.end());
	int ans = solve(0, N-1);
	cout << ans;
	return 0;
}