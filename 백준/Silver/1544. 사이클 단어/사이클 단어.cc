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
#define MAX_N 1000001

using namespace std;

int N;
set<string> dict;

bool foo(string s) {
	bool isExist = false;
	for(int i = 0; i < s.size(); i++) {
		string tmp = "";
		for(int j = 0; j < s.size(); j++) {
			tmp += s[(j+i)%s.size()];
		}
		if(dict.find(tmp) != dict.end()) {
			isExist = true;
		}
	}
	if(isExist) {
		return true;
	} else {
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int ans = 0;
	cin >> N;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		bool isExist = foo(s);
		if(!isExist) {
			ans++;
			dict.insert(s);
		}
	}
	cout << ans << '\n';
	return 0;
}