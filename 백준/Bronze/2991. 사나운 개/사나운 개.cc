#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <string>
#define INF 987654321
#define lld long long
#define MAX_N 1000001

using namespace std;

int A, B, C, D, P, M, N;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C >> D;
	cin >> P >> M >> N;
	int p, ans;
	p = (P-1) % (A+B);
	ans = 0;
	if(p < A) {
		ans++;
	}
	p = (P-1) % (C+D);
	if(p < C) {
		ans++;
	}
	cout << ans << endl;


	p = (M-1) % (A+B);
	ans = 0;
	if(p < A) {
		ans++;
	}
	p = (M-1) % (C+D);
	if(p < C) {
		ans++;
	}
	cout << ans << endl;


	p = (N-1) % (A+B);
	ans = 0;
	if(p < A) {
		ans++;
	}
	p = (N-1) % (C+D);
	if(p < C) {
		ans++;
	}
	cout << ans << endl;
	
	return 0;
}