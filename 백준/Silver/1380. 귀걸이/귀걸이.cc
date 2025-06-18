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


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int scenario = 1;
	while(true) {
		int n;
		cin >> n;
		if(n == 0) break;
		vector<string> v(n);
		vector<int> nv(n);
		cin.ignore();
		for(int i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			v[i] = s;
		}
		for(int i = 0; i < 2*n-1; i++) {
			int a;
			char c;
			cin >> a >> c;
			nv[a-1]++;
		}
		for(int i = 0; i < n; i++) {
			if(nv[i] == 1) {
				cout << scenario << ' ' << v[i] << '\n';
				scenario++;
				break;
			}
		}
	}
	return 0;
}
