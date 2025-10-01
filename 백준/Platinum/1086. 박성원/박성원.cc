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
#define MAX_N 15
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int N, k;
pii p[MAX_N];
int tens[51];
lld cache[(1 << MAX_N)][111];

lld solve(int s, int num) {
	if(s == (1 << N) - 1) return (num % k == 0);
	lld& ret = cache[s][num];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0; i < N; i++) {
		if(s & (1<<i)) continue;
		lld next = num * tens[p[i].second] + p[i].first; // 현재에서 오른쪽에 끼운다.
		next %= k;
		ret += solve(s | (1 << i), next);
	}
	return ret;
}

lld gcd(lld a, lld b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	lld all = 1;
	cin >> N;
	vector<string> s(N);
	for(int i = 0; i < N; i++) {
		cin >> s[i];
		all *= (i+1);
	}
	cin >> k;
	tens[0] = 1;
	for(int i = 1; i < 51; i++) {
		tens[i] = (tens[i-1]*(10%k)) % k;
	}
	for(int i = 0; i < N; i++) {
		p[i].second = s[i].size();
		for(int j = 0; j < s[i].size(); j++) {
			p[i].first = (p[i].first * (10 % k)) + (s[i][j]-'0') % k;
			p[i].first %= k;
		}
	}
	memset(cache, -1, sizeof(cache));
	lld cnt = solve(0, 0);
	lld g = gcd(all, cnt);
	// cout << all << ' ' << cnt << ' ' << g << endl;
	cout << cnt/g << '/' << all/g;
	return 0;
}

/*
x % k
(x*10^n) % k
(x%k * 10^n%k) % k


a % k
(a*10^n+b) % k
((a % k * 10^n % k) % k + b % k) % k


*/