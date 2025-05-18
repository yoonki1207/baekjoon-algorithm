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

int N;
vector<lld> v;
vector<lld> arr;

lld getParent(lld a) {
	if(arr[a] != a) return arr[a] = getParent(arr[a]);
	return a;
}

void unionNode(lld a, lld b) {
	lld pa = getParent(a);
	lld pb = getParent(b);
	if(pa < pb) arr[pb] = pa;
	else arr[pa] = pb;
}

// 두 수를 서로소로
void optimize(lld& a, lld& b) {
	lld gcd(lld, lld);
	lld x = gcd(a, b);
	a /= x;
	b /= x;
}

lld gcd(lld a, lld b) {
	if(b < a) {
		swap(a, b);
	}
	if(b == 0) {
		return a;
	}
	if(b % a == 0) {
		return a;
	} else {
		return gcd(a, b%a);
	}
}

lld gcd(vector<lld> v) {
	if(v.size() == 0) return 1;
	lld current_gcd = v[0];
	for(int i = 1; i < v.size(); i++) {
		if(v[i] == 0) continue;
		if(current_gcd == 0) {
			current_gcd = v[i];
		} else {
			current_gcd = gcd(current_gcd, v[i]);
		}
	}
	return current_gcd == 0 ? 1 : current_gcd;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	v = vector<lld>(N, 0);
	arr = vector<lld>(N, 0);
	if(N == 1) v[0] = 1;
	for(int i = 0; i < N; i++) arr[i] = i;

	for(int ii = 0; ii < N-1; ii++) {
		lld a, b, p, q;
		cin >> a >> b >> p >> q;
		if(v[a] == 0 && v[b] == 0) {
			optimize(p, q);
			v[a] = p; v[b] = q;
		} else if (v[a] == 0) { // v[a] 만 0
			v[a] = v[b] * p;
			lld pb = getParent(b);
			for(int i = 0; i < N; i++) {
				if(getParent(i) == pb) {
					v[i] *= q;
				}
			}
		} else if(v[b] == 0) { // v[b] 만 0
			v[b] = v[a] * q;
			lld pa = getParent(a);
			for(int i = 0; i < N; i++) {
				if(getParent(i) == pa) {
					v[i] *= p;
				}
			}
		} else { // 둘 다 0이 아님.
			lld pa = getParent(a);
			lld pb = getParent(b);
			lld va = v[a];
			lld vb = v[b];
			for(int i = 0; i < N; i++) {
				lld pi = getParent(i);
				if(pi == pa) {
					v[i] *= vb*p;
				} else if (pi == pb) {
					v[i] *= va*q;
				}
			}
		}
		unionNode(a, b);
		lld k = gcd(v);
		for(int j = 0; j < N; j++) {
			v[j] /= k;
		}
	}

	
	for(int i = 0; i < N; i++) {
		cout << v[i] << ' ';
	}
	
	return 0;
}
