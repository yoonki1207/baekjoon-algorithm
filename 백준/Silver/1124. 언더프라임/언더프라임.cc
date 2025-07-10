#include <iostream>
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

bool isNotPrime[100001];
vector<int> nPrime;

void init() {
	isNotPrime[0] = isNotPrime[1] = true;
	for(int i = 2; i <= 100000; i++) {
		if(isNotPrime[i] == true) continue;
		else {
			nPrime.push_back(i);
			for(int j = i*2; j <= 100000; j+=i) {
				isNotPrime[j] = true;
			}
		}
	}
}

vector<int> primeFactorization(int n) {
	vector<int> factors;
	int i = 0;
	while(isNotPrime[n] == true) {
		for(; i < nPrime.size(); i++) {
			if(n % nPrime[i] == 0) {
				factors.push_back(nPrime[i]);
				n = n / nPrime[i];
				break;
			}
		}
	}
	factors.push_back(n);
	return factors;
}

bool isUnerPrime(int n) {
	vector<int> pf = primeFactorization(n);
	return !isNotPrime[pf.size()];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	init();

	// start input
	int a, b;
	cin >> a >> b;
	int nCount = 0;
	for(int i = a; i <= b; i++) {
		if(isUnerPrime(i)) {
			nCount++;
		}
	}
	cout << nCount;
	
	return 0;
}