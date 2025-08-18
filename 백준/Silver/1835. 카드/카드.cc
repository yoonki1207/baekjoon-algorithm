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
#define MAX_N 10000
#define lld long long int
using namespace std;

int N;
int arr[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	queue<int> q;
	for(int i = 1; i <= N; i++) {
		q.push(i);
	}
	int n = 1;
	while(!q.empty()) {
		for(int i = 0; i < n; i++) {
			int x = q.front();
			q.pop();
			q.push(x);
		}
		int x = q.front();
		q.pop();
		arr[x] = n;
		n++;
	}
	for(int i = 1; i <= N; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}