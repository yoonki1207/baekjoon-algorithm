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
#define MAX_N 1000000000
#define lld long long int

using namespace std;

lld N, M, K; // 10억
lld cache[201][201];

lld comb(lld n, lld r) {
	r = min(r, n-r);
	if(r == 0) return cache[n][r] = 1;
	if(n<=1) return cache[n][r] = 1;
	if(cache[n][r] != 0) return cache[n][r];
	// lld ret = comb(n-1, r-1) + comb(n-1,r);
	lld a = comb(n-1, r-1);
	lld b = comb(n-1, r);
	lld ret = a + b;
	if(a < 0 || b < 0 || a+b > MAX_N) ret = -1;
	return cache[n][r] = ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cache[0][0] = 1;
	for(int i = 0; i <= 200; i++) {
		comb(200, i);
	}
	// for(int i = 0; i < 1; i++) {
	// 	for(int j = 0; j <= 200; j++) {
	// 		int n = 200;
	// 		int r = min(j, n-j);
	// 		cout << cache[n][r] << ' ';
	// 	}cout << endl;
	// }
	// cout << "FIN" << endl;
	cin >> N >> M >> K; // n c n/2 n=33일 때 10억이 넘어간다
	int len = N+M;
	vector<char> v(len);
	for(int i = 0; i < len; i++) {
		// 0의 개수 = (N+M-1) C (N-1)
		if(N==0) {
			// cout << 'z';
			v[i] = 'z';
			continue;
		} else if(M==0) {
			// cout << 'a';
			v[i] = 'a';
			continue;
		}
		lld cntA = comb(N+M-1, N-1);
		if(cntA < 0) {
			// cout << 'a';
			v[i] = 'a';
			N--;
		} else if(K <= cntA) {
			// cout << 'a';
			v[i] = 'a';
			N--;
		} else {
			// cout << 'z';
			v[i] = 'z';
			K -= cntA;
			M--;
		}
	}
	// cout << endl << K;
	if(K != 1) {
		cout << -1 << endl;
	} else {
		for(int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}
	return 0;
}

/*
N=2, M=2
0011
0101
0110
1001
1010
1100

N=3, M=2
00011
00101
00110
01001
01010
01100
10001
10010
10100
11000

N=4, M=1
00001
00010
00100
01000
10000

n,m에 대해 k번째 순열의 첫 수 = x

어짜피 k는 최대 10억이기 때문에 그 이상을 갖는 순열은 고려할 필요가 없음.
*/