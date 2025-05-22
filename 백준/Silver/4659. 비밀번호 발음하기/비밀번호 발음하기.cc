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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	while(true) {
		cin >> s;
		if(s.compare("end") == 0) break;
		int mcnt = 0, jcnt = 0;
		bool valid = true;
		bool mm = false;
		for(int i = 0; i < s.size(); i++) {
			if(i > 0 && s[i] == s[i-1]) {
				if (s[i] != 'e' && s[i] != 'o') {
					valid = false;
				}
			}
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				mcnt++;
				jcnt = 0;
				mm = true;
			} else {
				jcnt++;
				mcnt = 0;
			}
			if(mcnt >= 3 || jcnt >= 3) {
				valid = false;
			}
		}
		if(mm == false) valid = false;
		cout << '<' << s << '>' << " is " << (valid ? "": "not ") << "acceptable.\n";
	}
	return 0;
}

/*
0 1 2 3 4

1 3 0 2 4
*/