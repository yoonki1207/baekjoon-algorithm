#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321

using namespace std;

int n;
vector<pair<int, int>> v;
vector<pair<int, int>> p;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v = vector<pair<int, int>>(n);
	int start_index = 0, min_x = INF, min_y = INF;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		if (min_x > v[i].first && min_y > v[i].second) {
			min_x = v[i].first;
			min_y = v[i].second;
			start_index = i;
		}
	}
	bool open = false;
	pair<int, int> prev_coord = { 0, 0 };
	for (int i = 1; i < n; i++) {
		int index = (i + start_index) % n;
		int prev_index = (index - 1 + n) % n;
		pair<int, int> curr_coord = v[index];
		if ((v[prev_index].second > 0 && curr_coord.second < 0) ||
			(v[prev_index].second < 0 && curr_coord.second > 0)) {
			open = !open;
			if (open == false) {
				pair<int, int> left, right;
				if (prev_coord.first < curr_coord.first) {
					left = prev_coord;
					right = curr_coord;
				}
				else {
					left = curr_coord;
					right = prev_coord;
				}
				p.push_back({ left.first, 1 });
				p.push_back({ right.first, -1 });
			}
			else {
				prev_coord = curr_coord;
			}
		}
	}
	sort(p.begin(), p.end());
	int cnt = 0;
	int prev = 0;
	int ansA = 0;
	int ansB = 0;
	for (int i = 0; i < p.size(); i++) {
		if (p[i].second > 0) {
			cnt++;
		}
		else {
			cnt--;
		}
		if (cnt == 0) {
			ansA++;
		}
		if (prev > 0 && p[i].second < 0) {
			ansB++;
		}
		prev = p[i].second;
	}
	cout << ansA << ' ' << ansB;

	return 0;
}