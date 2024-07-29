#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#define lld long long int
#define MAX_N 10000002

using namespace std;

bool notPrime[MAX_N + 1];

void initPrime() {
	notPrime[0] = notPrime[1] = true;
	for(int i = 2; i <= MAX_N; i++) {
		if(notPrime[i] == false) {
			for(int j = 2; i*j <= MAX_N; j++) {
				notPrime[i*j] = true;
			}
		}
	}
}

bool isPrime(int n) {return !notPrime[n];}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	// cout << pow((long long)100000000000000, (double)1/3);
	lld a, b;
	initPrime();
	cin >> a >> b;
	int ans = 0;
	for(int i = 2; i <= MAX_N; i++) {
		if(isPrime(i)) {
			lld n = i;
			while(n <= b/i) {
				if(a <= n*i) ans++;
				n *= i;
			}
		}
	}
	cout << ans;
	return 0;
}
// 10000000
// 100000000000000
// 100000000000000