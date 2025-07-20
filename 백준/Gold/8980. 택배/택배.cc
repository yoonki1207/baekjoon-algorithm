#include <iostream>
#include <iomanip>
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

int N, C, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	
	cin >> N >> C;
	cin >> M;

	vector<pair<int, pair<int, int>>> v;

	for(int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({b, {a, c}}); // destination, start, total weight
	}

	sort(v.begin(), v.end());

	int truck_size[2001] = {0};
	int ans = 0;

	for(int i = 0; i < v.size(); i++) {
		const int start = v[i].second.first;
		const int destination = v[i].first;
		const int box_weight = v[i].second.second;
		int filled = 0;
		for(int j = start; j < destination; j++) {
			filled = max(filled, truck_size[j]);
		}
		int space = C - filled;
		int addtional_weight = min(space, box_weight);
		ans += addtional_weight;

		for(int j = start; j < destination; j++) {
			truck_size[j] += addtional_weight;
		}
	}
	cout << ans << endl;

	
	return 0;
}

// 특정 지점에서 특정 택배를 배달할 때 최대값
// 8980
/*
1. Greedy 아니다.
2. DP인가? 모르겠다. 

*/