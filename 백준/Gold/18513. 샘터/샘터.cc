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
#define lld long long

using namespace std;

int N, K;
vector<int> water;
unordered_map<int, bool> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	water = vector<int>(N);
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		cin >> water[i];
		m.insert({ water[i], true });
		q.push({ 1, water[i] });
	}
	lld ans = 0;
	while (!q.empty()) {
		int distance = q.front().first;
		int water_index = q.front().second;
		q.pop();
		
		int left_index = water_index + distance;
		int right_index = water_index - distance;
		bool left_done = false, right_done = false;
		if (m.find(left_index) == m.end()) {
			m.insert({ left_index, true });
			--K;
			ans += distance;
			left_done = true;
		}
		if (K == 0) {
			break;
		}
		if (m.find(right_index) == m.end()) {
			m.insert({ right_index, true });
			--K;
			ans += distance;
			right_done = true;
		}
		if (K == 0) {
			break;
		}
		if (left_done || right_done) {
			q.push({ distance + 1, water_index });
		}
	}
	cout << ans << endl;
	return 0;
}
