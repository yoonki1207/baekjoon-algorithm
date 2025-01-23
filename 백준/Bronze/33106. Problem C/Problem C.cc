#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

string solve(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'c') {
			if (i == s.size() - 1) { // last c
				s[i] = 'k';
			}
			else if (s[i + 1] == 'h') { // ch
				s = s.substr(0, i + 1) + s.substr(i + 2);
			}
			else if (s[i+1] == 'e' || s[i+1]=='i' || s[i+1] =='y') {
				s[i] = 's';
			}
			else {
				s[i] = 'k';
			}

		}
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		s = solve(s);
		cout << s << '\n';
	}
	return 0;
}