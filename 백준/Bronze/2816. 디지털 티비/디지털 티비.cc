#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#define INF 987654321
#define MAX_N 1503
#define lld long long
#define pii pair<int, int>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

// 백준 2816
int N;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	v = vector<string>(N);
	int k1 = 0, k2 = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (v[i].compare("KBS1") == 0) {
			k1 = i;
		}
		else if (v[i].compare("KBS2") == 0) {
			k2 = i;
		}
	}
	int index = 0;
	if (k1 < k2) {
		for (int i = 0; i < k1; i++) {
			cout << '1';
		}
		for (int i = 0; i < k1; i++) {
			cout << '4';
		}
		for (int i = 0; i < k2; i++) {
			cout << '1';
		}
		for (int i = 0; i < k2-1; i++) {
			cout << '4';
		}
	}
	else {
		for (int i = 0; i < k2; i++) {
			cout << '1';
		}
		for (int i = 0; i < k2; i++) {
			cout << '4';
		}
		for (int i = 0; i < k1; i++) {
			cout << '1';
		}
		for (int i = 0; i < k1; i++) {
			cout << '4';
		}
	}
	return 0;
}
