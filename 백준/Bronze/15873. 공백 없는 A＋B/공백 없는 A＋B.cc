#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321
#define lld long long
#define ull unsigned long long
#define MAX_N 500000

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	string b = "";
	int i = 0;
	if(s.size()>2) {
		if(s[1] == '0') {
			cout << stoi(s.substr(0, 2))+stoi(s.substr(2, s.size()-2));
		} else {
			cout << (s[0]-'0') + stoi(s.substr(1, s.size()-1));
		}
	} else {
		cout << (s[0]-'0'+s[1]-'0');
	}

	
	return 0;
}
