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

using namespace std;

int N, L, R;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<int> v(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int nQ;
	cin >> nQ;
	while(nQ-->0) {
		cin >> L >> R;
		int j = L;
		for(int i = 0; i < N; i++) {
			if(v[i] >= L && v[i] <= R) {
				cout << j;
				j++;
			} else {
				cout << v[i];
			}
			if(i != N-1) cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}

// 10 9 8 7 6