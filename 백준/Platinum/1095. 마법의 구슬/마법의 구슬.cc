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
#define MAX_N 100001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

lld S, F, M;
bool isPrime[MAX_N];
vector<int> prime;
vector<int> cnt;

int calc(int pn, int num) {
	int ret = 0;
	while((int)(num / pn) > 0) {
		num /= pn;
		ret += num;
	}
	return ret;
}

void initPrimes() {
	// initialize prime using Sieve of Aratosthenes
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for(int num = 2; num <= MAX_N; num++) {
		if(isPrime[num] == true) {
			for(int i = num+num; i <= MAX_N; i += num) {
				isPrime[i] = false;
			}
			// input prime
			prime.push_back(num);
			// cnt
			cnt.push_back(calc(num, S+F) - calc(num, S) - calc(num, F));
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> S >> F >> M;
	initPrimes();
	int ans = 1;
	for(int i = M; i >= 1; i--) {
		int tmp = i;
		bool flag = true;
		for(int j = 0; j < prime.size(); j++) {
			int count = 0;
			while(tmp % prime[j] == 0) {
				tmp /= prime[j];
				count++;
			}
			if(count > cnt[j]) {
				flag = false;
				break;
			}
		}
		if(flag) {
			ans = i;
			break;
		}
	}
	cout << ans;

	return 0;
}