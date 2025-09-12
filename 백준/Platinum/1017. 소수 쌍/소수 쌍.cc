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
#define MAX_N 1000
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

bool isntPrime[2000];
int N;
vector<int> v;

inline int isPrime(int n) {return !isntPrime[n];}
void init() {
	isntPrime[0] = isntPrime[1] = true;
	for(int i = 2; i < MAX_N*2; i++) {
		if(isntPrime[i] == false) {
			for(int j = i*2; j < MAX_N*2; j += i) {
				isntPrime[j] = true;
			}
		}
	}
}

lld f(int n) {
	if(n <= 2) return 1ll;
	return (n/2)*f(n-2);
}

vector<int> vtx[MAX_N+1];
int slt[MAX_N+1];
bool done[MAX_N+1];
int k;

bool dfs(int x) { // done a->p, slt[p] = a
	if(x == k) return false;
	for(int i = 0; i < vtx[x].size(); i++) {
		int p = vtx[x][i];
		if(done[p] == true) continue;
		done[p] = true;
		if(slt[p] == 0 || dfs(slt[p])) {
			slt[p] = x;
			return true;
		}
	}
	return false;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	init();
	vector<int> odd, even;
	// int k = 0;
#ifndef DEBUG
	cin >> N;
	v = vector<int>(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
		if(i == 0) k = v[i];
		if(v[i] % 2 == 0) {
			even.push_back(v[i]);
		} else {
			odd.push_back(v[i]);
		}
	}
#endif
#ifdef DEBUG
	N = 50;
	v = vector<int>(N);
	for(int i = 0; i < N; i++) {
		// cin >> v[i];
		v[i] = i+1;
		if(i == 0) k = v[i];
		if(v[i] % 2 == 0) {
			even.insert(v[i]);
		} else {
			odd.insert(v[i]);
		}
	}
#endif
	if(even.size() != odd.size()) {
		cout << "-1\n";
		return 0;
	}
	vector<int> ans;
	vector<int> a_set, b_set;
	if(k % 2 == 0) {
		a_set = even;
		b_set = odd;
	} else {
		a_set = odd;
		b_set = even;
	}

	for(int i = 0; i < a_set.size(); i++) {
		for(int j = 0; j < b_set.size(); j++) {
			if(isPrime(a_set[i]+b_set[j]))
				vtx[a_set[i]].push_back(b_set[j]);
		}
	}

	for(int i = 0; i < vtx[k].size(); i++) {
		int p = vtx[k][i];
		int cnt = 1;
		fill(slt, slt+MAX_N+1, 0);
		slt[p] = k;
		for(int j = 0; j < a_set.size(); j++) {
			fill(done, done+MAX_N+1, false);
			done[p] = true;
			if(dfs(a_set[j])) {
				cnt++;
			}
		}
		if(cnt == N/2) {
			ans.push_back(p);
		}
	}

	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}

	if(ans.size() == 0) {
		cout << "-1\n";
	}
	

	return 0;
}
