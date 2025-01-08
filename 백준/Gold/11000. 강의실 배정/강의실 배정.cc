#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 2000001
#define lld long long int

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	for(vector<pair<int, int>>::iterator iter = v.begin(); iter != v.end(); ++iter) {
		int start_time = iter->first;
		int end_time = iter->second;
		pq.push(end_time);
		if(pq.top() <= start_time) pq.pop();
	}
	cout << pq.size();
	
	return 0;
}
