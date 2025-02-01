
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int T;
	cin >> T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		int arr[501][501]={0};
		int prr[501] = {0};
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) {
			cin >> v[i];
			prr[v[i]] = i;
		}
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				arr[v[i]][v[j]] = 1;
			}
		}
		queue<int> q;

		int m;
		cin >> m;
		for(int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			swap(arr[a][b], arr[b][a]);
			prr[a] += arr[a][b] == 0 ? 1 : -1;
			prr[b] += arr[b][a] == 0 ? 1 : -1;
		}
		vector<pair<int, int>> vp;
		vp.reserve(n);
		for(int i = 1; i <= n; i++) {
			vp.push_back({prr[i], i});	
		}

		sort(vp.begin(), vp.end());
		bool isPossible = vp[0].first == 0;
		for(int i = 0; i < vp.size()-1 && isPossible; i++) {
			if(vp[i].first >= vp[i+1].first) {
				isPossible = false;
			}
		}

		if(!isPossible) {
			cout << "IMPOSSIBLE\n";
		} else {
			for(int i = 0; i < n; i++) cout << vp[i].second << ' ';
			cout << '\n';
		}
	}
	return 0;
}
