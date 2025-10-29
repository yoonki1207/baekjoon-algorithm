#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#define INF 987654321
#define MAX_N 1503
#define lld long long

using namespace std;

// 백준 17225

int A, B, N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> N;
	int t, m;
	char color;
	int pa = 0, pb = 0;
	vector<pair<int, int>> v; // false: sangmin
	for (int i = 0; i < N; i++) {
		cin >> t >> color >> m;
		if (color == 'B' && t < pa) t = pa;
		if (color == 'R' && t < pb) t = pb;
		for (int j = 0; j < m; j++) {
			// t, color
			v.push_back({ t, color == 'R'? 1 : 0 });
			t += (color == 'B') ? A : B;
		}
		if (color == 'B') {
			pa = t;
		}
		if (color == 'R') {
			pb = t;
		}
	}

	sort(v.begin(), v.end());
	vector<int> sangmin, jisu;
	for (vector<pair<int, int>>::iterator iter = v.begin(); iter != v.end(); iter++) {
		if (iter->second == 0) {
			sangmin.push_back((iter - v.begin()) + 1);
		}
		else {
			jisu.push_back((iter - v.begin()) + 1);
		}
	}
	cout << sangmin.size() << '\n';
	for (int i = 0; i < sangmin.size(); i++) {
		cout << sangmin[i] << ' ';
	}cout << '\n';
	cout << jisu.size() << '\n';
	for (int i = 0; i < jisu.size(); i++) {
		cout << jisu[i] << ' ';
	}cout << '\n';
	return 0;
}
