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
	int n, m;
	cin >> n >> m;
	priority_queue<lld, vector<lld>, greater<lld>> pq;
	for(int i = 0; i < n; i++) {
		lld x;
		cin >> x;
		pq.push(x);
	}
	for(int i = 0; i < m; i++) {
		lld x = pq.top();
		pq.pop();
		lld y = pq.top();
		pq.pop();
		pq.push(x+y);
		pq.push(x+y);
	}
	lld ans = 0;
	while(!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans << endl;
	
	return 0;
}
