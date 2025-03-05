#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while(T-->0) {
		string s;
		cin >> s;
		int k;
		cin >> k;

		vector<int> cnt[256];
		for(char c = 'a'; c <= 'z'; c++) cnt[c] = vector<int>();
		for(int i = 0; i < s.size(); i++) {
			cnt[s[i]].push_back(i);
		}
		int min_len = INF, max_len = 0;
		for(char c = 'a'; c <= 'z'; c++) {
			vector<int>& v = cnt[c];
			for(int i = 0; i < (int)v.size() - k + 1; i++) {
				min_len = min(min_len, v[i+k-1] - v[i] + 1);
				max_len = max(max_len, v[i+k-1] - v[i] + 1);
			}
		}
		if(min_len == INF) cout << "-1\n";
		else cout << min_len << ' ' << max_len << '\n';
	}
	
	return 0;
}