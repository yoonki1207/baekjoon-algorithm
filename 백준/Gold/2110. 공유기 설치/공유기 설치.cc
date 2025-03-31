#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int N, C;
vector<int> v;

bool setShare(int min_gap) {
	vector<int> stk;
	stk.push_back(v[0]);
	for(int i = 1; i < v.size(); i++) {
		if(min_gap <= v[i] - stk.back()) {
			stk.push_back(v[i]);
		}
	}
	return stk.size() >= C;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> N >> C;
	v = vector<int>(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int ans = 1;
	int left = 0, right = 1000000001;
	while(left <= right) {
		int mid = (left + right) / 2;
		if(setShare(mid)) {
			ans = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	cout << ans << endl;

	return 0;
}