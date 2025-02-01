
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int test_case;
	int T;
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		int arr[501][501]={0};
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) {
			cin >> v[i];
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
		}
		int prr[501] = {0};
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(arr[i][j] == 1) prr[j]++;
			}
		}

		bool isPossible = false;
		for(int i = 1; i <= n; i++) {
			if(prr[i] == 0) {
				isPossible = true;
				q.push(i);
				break;
			}
		}
		vector<int> ans;
		while(!q.empty()) {
			int t = q.front();
			q.pop();
			for(int i = 1; i <= n; i++) {
				if(arr[t][i] == 1) {
					arr[t][i] = 0;
					prr[i]--;
					if(prr[i] == 0) q.push(i);
				}
			}
			ans.push_back(t);
		}
		if(ans.size() != n) isPossible = false;

		if(!isPossible) {
			cout << "IMPOSSIBLE\n";
			continue;
		} else {
			for(int i = 0; i < n; i++) cout << ans[i] << ' ';
			cout << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
