#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321
#define MAX_N 65537
#define lld long long int
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		cout << (char)(s[i]+('A'-'a'));
	}
	return 0;
}
