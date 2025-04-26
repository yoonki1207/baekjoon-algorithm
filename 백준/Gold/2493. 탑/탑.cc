#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int N;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	v = vector<int>(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}

	vector<int> t;
	vector<int> ans(N);
	for(int i = 0; i < N; i++) {
		while(!t.empty() && v[t.back()] < v[i]) {
			t.pop_back();
		}
		if(t.empty()) {
			ans[i] = 0;
			t.push_back(i);
		} else {
			ans[i] = t.back() + 1;
			t.push_back(i);
		}
	}
	for(int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	
	return 0;
}

// 10 9 8 7 6