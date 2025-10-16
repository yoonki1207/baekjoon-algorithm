#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int n;
vector<pair<int, int>> inputs;
vector<int> arr;
vector<int> ans;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int max_val = 0, a, b;
	vector<pair<int, pair<int, int>>> tmp;
	for (int i = 0; i < n; i++) {
		//cin >> inputs[i].first >> inputs[i].second;
		cin >> a >> b;
		tmp.push_back({ a, {i, 0} });
		tmp.push_back({ b, {i, 1} });
		//max_val = max(max_val, inputs[i].second);
	}
	// coordinate zip
	int next_val = 1;
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++) {
		tmp[i].first = next_val++;
	}
	max_val = next_val;
	inputs = vector<pair<int, int>>(max_val);
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i].second.second == 0) {
			inputs[tmp[i].second.first].first = tmp[i].first;
		}
		else {
			inputs[tmp[i].second.first].second = tmp[i].first;
		}
	}

	arr = vector<int>(max_val + 1);
	ans = vector<int>(max_val + 1);
	for (int i = 0; i < n; i++) {
		arr[inputs[i].first] = -1;
		arr[inputs[i].second] = inputs[i].first;
	}

	for (int i = 1; i <= max_val; i++) {
		if (arr[i] == 0) {
			continue;
		}
		else if (arr[i] == -1) {
			v.push_back(i);
		}
		else {
			int val = arr[i];
			/*cout << "find " << val << endl;
			for (int j = 0; j < v.size(); j++) {
				cout << v[j] << ' ';
			}cout << endl;*/
			vector<int>::iterator found = lower_bound(v.begin(), v.end(), val);
			v.erase(found);
			for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
				if (*iter >= val) break;
				ans[*iter]++;
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= max_val; i++) {
		ret = max(ret, ans[i]);
	}
	cout << ret << endl;

	return 0;
}