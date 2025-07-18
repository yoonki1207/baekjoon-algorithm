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
#define lld long long
#define ull unsigned long long
#define MAX_N 500000

using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(v.empty()) {
			v.push_back(x);
		} else {
			if(v.back() < x) {
				v.push_back(x);
			} else {
				auto iter = lower_bound(v.begin(), v.end(), x);
				*iter = x;
			}
		}
	}
	cout << v.size();

	return 0;
}