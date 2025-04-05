#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#define INF 987654321
#define lld long long

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) { // clockwise = negative
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int manhattanDistance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int N;
		cin >> N;
		vector<pair<int, int>> v(N);
		vector<bool> visited(N);
		int sx = -200, sy = -200, si = 0; // standard x, y and index
		for (int i = 0; i < N; i++) {
			int x, y; cin >> x >> y;
			v[i].first = x;
			v[i].second = y;
			if (y > sy) {
				sy = y;
				sx = x;
				si = i;
			}
			else if (y == sy) {
				sx = min(sx, x);
				si = i;
			}
		}
		visited[si] = true;
		int ax, ay, bx, by, cx, cy;
		// find first b
		ax = sx; ay = sy;
		bx = visited[0] ? v[1].first : v[0].first;
		by = visited[0] ? v[1].second : v[0].second;
		int index = visited[0] ? 1 : 0;
		if (visited[0]) visited[1] = true;
		vector<pair<int, int>> ans;
		ans.push_back({ ax, ay });
		while (ans.size() < N) {
			for (int i = 0; i < N; i++) {
				// a, b, c 의 ccw 결과가 음수면 b 유지
				// 양수면 c가 b
				// 0이면 b, c 중에 가까운 이 b
				// 모든 점을 돌았을 때 b가 다음 점이다.
				//if (visited[i] == true) continue;
				int val = ccw(ax, ay, bx, by, v[i].first, v[i].second);
				if (val > 0) {
					bx = v[i].first;
					by = v[i].second;
					index = i;
				}
				else if (val == 0) {
					if (
						manhattanDistance(ax, ay, bx, by) <
						manhattanDistance(ax, ay, v[i].first, v[i].second)
						&& !(ax == v[i].first && ay == v[i].second)) {
						bx = v[i].first;
						by = v[i].second;
						index = i;
					}
				}
			}
			if (bx == ans[0].first && by == ans[0].second) break;
			ans.push_back({ bx, by });
			ax = bx;
			ay = by;
			bx = ans[0].first;
			by = ans[0].second;
			visited[index] = true;
		}
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << ' ' << ans[i].second << '\n';
		}
	}
	return 0;
}