#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321
#define MAX_N 1000001
#define lld long long int
#define pii pair<int, int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		q.push(i);
	}
	while(!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
		q.push(q.front());
		q.pop();
	}

	return 0;
}
