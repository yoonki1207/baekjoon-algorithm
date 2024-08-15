#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#define lld long long int
#define MAX_N 10000002

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int T;
	cin >> T;
	while(T-->0) {
		string s;
		cin >> s;
		int n = (int)sqrt(s.size());
		for(int i = n-1; i >= 0; i--) {
			for(int j = 0; j < n; j++) {
				cout << s[j*n+i];
			}
		}
		cout << '\n';
	}
	return 0;
}