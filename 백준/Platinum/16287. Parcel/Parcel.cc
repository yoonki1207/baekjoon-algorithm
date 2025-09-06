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
#define MAX_N 800000
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int n, w;
int cache1[MAX_N], cache2[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> w >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	memset(cache1, -1, sizeof(cache1));
	memset(cache2, -1, sizeof(cache2));
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int weight = v[i] + v[j];
			if(cache1[weight] == -1) {
				cache1[weight] = i;
				cache2[weight] = j;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			int weight = w - (v[i] + v[j]);
			if(weight > 400000 || weight < 0 || cache1[weight] < 0) {
				continue;
			}
			if(cache1[weight] != i && cache2[weight] != j && cache1[weight] != j && cache2[weight] != i) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}
