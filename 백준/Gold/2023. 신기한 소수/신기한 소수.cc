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
#define MAX_N 51
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int N;
bool isntPrime[100001];

void initPrimes() {
	isntPrime[0] = isntPrime[1] = true;
	for(int i = 2; i <= 100000; i++) {
		if(isntPrime[i] == false) {
			for(int j = i*2; j <= 100000; j+=i) {
				isntPrime[j] = true;
			}
		}
	}
}

bool isPrime(int x) {
	//      12345678
	if(x >= 100000) {
		for(int i = 2; i <= sqrt(x); i++) {
			if(x%i == 0) return false;
		}
		return true;
	}
	return !isntPrime[x];
}

void dfs(int x, int depth) {
	if(depth == N) {
		cout << x << '\n';
		return;
	}
	int k = x;
	for(int i = 1; i <= 9; i++) {
		k = x*10+i;
		if(isPrime(k)) {
			dfs(k, depth+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	initPrimes();
	cin >> N;
	dfs(0, 0);

	return 0;
}