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
#define ull unsigned long long
#define MAX_N 1000001

using namespace std;

map<string, bool> visitedSet;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ull X, K;
	cin >> X >> K;
	
	ull t = 1;
	ull ans = 0;
	for(ull i = 1; i <= __LONG_LONG_MAX__; i = i << 1) {
		if((X&i) == 0) {
			ans |= (K & t) ? i : 0;
			t = t << 1;
		}
	}
	cout << ans << endl;
	
	return 0;
}
/*
5 5
0000 0101
0000 0101
0001 0111
0001 0010


5 1
0101
0001
0010
*/