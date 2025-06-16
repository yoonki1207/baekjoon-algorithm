#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define lld long long int

using namespace std;

vector<lld> v;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c == ')') {
			lld len = 0;
			while (v.back() != '(') {
				if (v.back() >= '0') {
					len++;
				}
				else {
					len -= v.back();
				}
				v.pop_back();
			}
			v.pop_back();
			len = len * (v.back() - '0');
		    //cout << len << ' ';
		    v.pop_back();
			v.push_back(-len);
		}
		else {
			v.push_back(s[i]);//33(562(71(9)))
		}
	}
	lld ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > 0) ans++;
		else ans -= v[i];
	}
	cout << ans << endl;



	return 0;
}