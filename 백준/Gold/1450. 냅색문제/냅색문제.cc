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
#define MAX_N 1000000000
#define lld long long int

using namespace std;

int N, C;

int dfs(vector<int>& v, int index, int weight, vector<int>& a) {
	int ret = 0;
	if(index == v.size()) {
		a.push_back(weight);
		return 1;
	}
	ret += dfs(v, index + 1, weight, a);
	if(v[index] + weight <= C) ret += dfs(v, index + 1, weight + v[index], a);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	// vector<int> v;
	// v.push_back(3);
	// v.push_back(10);
	// v.push_back(10);
	// v.push_back(20);
	// v.push_back(20);
	// auto iter = upper_bound(v.begin(), v.end(), 10);
	// if(iter == v.end()) cout << "end"; else cout << *iter;
	cin >> N >> C;
	int mid = N/2;
	vector<int> v1(mid);
	vector<int> v2(N-mid);
	vector<int> a1;
	vector<int> a2;
	for(int i = 0; i < mid; i++) {
		cin >> v1[i];
	}
	for(int i = 0; i < N-mid; i++) {
		cin >> v2[i];
	}
	int ans = 0;
	dfs(v1, 0, 0, a1);
	dfs(v2, 0, 0, a2);
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	for(int i = 0; i < a1.size(); i++) {
		int weight = C - a1[i];
		if(weight < a2[0]) {
			ans += 1;
			continue;
		}
		vector<int>::iterator iter = upper_bound(a2.begin(), a2.end(), weight);
		int gap = (int)(iter - a2.begin());
		ans += gap;
		
	}
	cout << ans;
	return 0;
}
