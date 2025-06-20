#include <iostream>
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

int N;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	lld nSum = 0;
	vector<int> zeros;
	vector<pair<int, int>> nums;
	for(int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		nSum += (lld)x;
		if(x == 0) {
			zeros.push_back(i);
		} else {
			nums.push_back({i, x});
		}
	}
	if(nSum != N-1 || zeros.size() == 0) {
		cout << -1;
		return 0;
	}
	int cnt = 0;
	vector<int> ans(N*2-1);
	while(cnt < N*2-1) {
		if(cnt % 2 == 0) {
			if(zeros.size() == 0) {
				cout << -1; return 0;
			}
			ans[cnt] = zeros.back();
			zeros.pop_back();
		} else {
			if(nums.size() == 0) {
				cout << -1; return 0;
			}
			ans[cnt] = nums.back().first;
			nums.back().second--;
			if(nums.back().second == 0) {
				zeros.push_back(nums.back().first);
				nums.pop_back();
			}
		}
		cnt++;
	}

	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}
