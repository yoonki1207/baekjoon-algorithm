#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <set>
#define INF 987654321
#define lld long long

#define MAX_N 200
#define MAX_K 1000
#define pipii pair<int, pair<int, int>>

using namespace std;

int N, M, L;
int ans;
vector<int> v;

bool isPossible(int interval) {
	int cnt = 0;
	for (int i = 1; i < v.size(); i++) {
		int diff = v[i] - v[i - 1];
		cnt += diff / interval;
		if (diff%interval == 0) {
			cnt--;
		}
	}
	return cnt <= M;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> L;
	v = vector<int>(N);
	v.push_back(0);
	v.push_back(L);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int left = 1, right = L;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (isPossible(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans;
	return 0;
}