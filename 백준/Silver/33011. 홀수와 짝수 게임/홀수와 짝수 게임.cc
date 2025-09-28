#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#include <string.h>
#define INF 987654321
#define MAX_N 75000
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int T, N, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >> T;
	for(int test_case = 0; test_case < T; test_case++) {
		cin >> N;
		int a = 0, b = 0;
		for(int i = 0; i < N; i++) {
			cin >> x;
			if(x % 2 == 0) b++; else a++;
		}
		if(a > b) swap(a, b);
		if(b % 2 && a != b) {
			cout << "amsminn\n";
		} else {
			cout << "heeda0528\n";
		}
	}


	return 0;
}
