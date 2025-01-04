#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 2000001

using namespace std;

int n, m;
vector<bool> isPrime(MAX_N, true);

void initPrime() {
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i < MAX_N / 2; i++) {
		if(isPrime[i]) {
			for(int j = i*2; j < MAX_N; j+=i) {
				isPrime[j] = false;
			}
		}
	}
}

int findArr(int s, const int n, const int m) {
	for(int i = 0; i < n; i++) {
		int index = s+i*m;
		if(index >= MAX_N) return -1;
		bool p = isPrime[index];
		if(p) {
			// break and findArr start with s+i*m+1
			return findArr(s+1, n, m);
		}
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	initPrime();
	cin >> n >> m;
	int s = findArr(1, n, m);
	if(s > 0) {
		for(int i = 0; i < n; i++) {
			cout << (s + i*m) << ' ';
		}
	} else {
		cout << -1;
	}
	return 0;
}

