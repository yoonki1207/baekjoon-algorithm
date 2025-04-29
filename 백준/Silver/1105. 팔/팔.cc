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

using namespace std;

string L, R;
int m = 0;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> L >> R;
	if(L.size() != R.size()) {
		cout << 0;
	} else {
		for(int i = 0; i < L.size(); i++) {
			if(L[i] != R[i]) {
				break;
			}
			
			if(L[i] == R[i] && L[i] == '8'){
				m++;
			}
		}
		cout << m;
	}
	return 0;
}