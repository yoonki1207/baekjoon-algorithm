#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#define lld long long int
#define MAX_N 10000002

using namespace std;

bool checkGoldminNumber(int n) {
	while(n>0) {
		int x = n%10;
		if(x != 7 && x != 4) {
			return false;
		}
		n /= 10;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = n; i>=4; i--) {
		if(checkGoldminNumber(i)) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}