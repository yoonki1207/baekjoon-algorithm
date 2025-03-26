#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int n, h, t;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> n >> h >> t;
	priority_queue<int> pq;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		pq.push(x);
	}
	int cnt = 0;
	while(pq.top() >= h && cnt < t) {
		int x = pq.top();
		pq.pop();
		pq.push(max(x/2,1));
		cnt++;
	}
	if(pq.top() >= h || cnt > t) {
		cout << "NO\n" << pq.top() << '\n';
	} else {
		cout << "YES\n" << cnt << endl;
	}
	return 0;
}