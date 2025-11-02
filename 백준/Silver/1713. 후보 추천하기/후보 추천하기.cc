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
#define pii pair<int, int>

using namespace std;

// 백준 1713

int N, M;

int arr[101];

bool isIn(const vector<pair<int, int>> v, int val) {
	for (int i = 0; i < v.size(); i++) if (v[i].first == val) return true;
	return false;
}

int delStuIndex(const vector<pair<int, int>> v) {
	int t = v[0].second;
	int votes = arr[v[0].first];
	int index = 0;
	for (int i = 1; i < v.size(); i++) {
		if (arr[v[i].first] < votes) {
			votes = arr[v[i].first];
			index = i;
			t = v[i].second;
		}
		else if (arr[v[i].first] == votes && t < v[i].second) {
			index = i;
			t = v[i].second;
		}
	}
	return index;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	vector<pair<int, int>> v;
	while (M--) {
		int x;
		cin >> x;
		if (v.size() < N) {
			arr[x]++;
			if (isIn(v, x)) {
				continue;
			}
			else {
				v.push_back({ x, M });
			}
		}
		else {
			arr[x]++;
			if (!isIn(v, x)) {
				int deli = delStuIndex(v);
				arr[v[deli].first] = 0;
				v.erase(v.begin() + deli);
				v.push_back({ x, M });
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}
	return 0;
}