#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int n;
typedef struct Trie {
	map<char, Trie*> m;
} Trie;
vector<string> ans;
map<string, int> w;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	Trie* root = new Trie();
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		Trie* next = root;
		int j = 0;
		bool pushed = false;
		for(j = 0; j < s.size(); j++) {
			auto iter = next->m.find(s[j]);
			if(iter == next->m.end()) {
				pushed = true;
				ans.push_back(s.substr(0, j+1));
				while(j<s.size()) {
					next->m.insert({s[j], new Trie()});
					next = next->m.at(s[j]);
					j++;
				}
				break;
			} else {
				next = iter->second;
			}
		}
		auto iter = w.find(s);
		if(iter == w.end()) {
			w.insert({s, 1});
			if(!pushed)
				ans.push_back(s);
		} else if(!pushed) {
			int n = iter->second + 1;
			w.at(s) = n;
			ans.push_back(s+to_string(n));
		}
	}
	// cout << " ans " << endl;
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	
	return 0;
}
