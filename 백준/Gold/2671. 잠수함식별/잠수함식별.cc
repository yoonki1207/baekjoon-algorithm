#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

// (100~1|01~)
bool isValid(string s) {
	if(s.size() == 0) return true; // TODO
	// cout << s << endl;
	if(s[0] == '0') {
		if(s.size() <= 1) return false;
		if(s[1] == '1') return isValid(s.substr(2));
		return false;
	} else {
		if(s.size()<4) return false;
		if(s[1] == '0' && s[2] == '0') {
			int index = 2;
			while(index < s.size() && s[index] == '0') {
				index++;
			}
			if(index == s.size()) return false;
			while(index < s.size() && s[index] == '1') {
				index++;
			}// 111100101
			if(s[index-2] == '1')
			return isValid(s.substr(index-1)) || isValid(s.substr(index));
			else 
				return isValid(s.substr(index));
		}
		return false;
	}
	return true;
}
// 1001001


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	cout << (isValid(s) ? "SUBMARINE" : "NOISE") << endl;
	return 0;
}
