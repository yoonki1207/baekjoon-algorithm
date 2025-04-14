#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int M;
map<int ,int> m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M;
	while(M-->0) {
		int cmd, x, w;
		cin >> cmd;
		if(cmd == 1) {
			cin >> x >> w;
			m.insert({w, x});
		} else {
			cin >> w;
			int x = m.find(w)->second;
			cout << x << '\n';
		}
	}
	return 0;
}