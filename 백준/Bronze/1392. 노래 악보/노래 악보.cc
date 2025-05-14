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

int N, Q;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for(int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		for(int j = 0; j < x; j++) {
			v.push_back(i);
		}
	}
	for(int i = 0; i < Q; i++) {
		int x; cin >> x;
		cout << v[x] << '\n';
	}
		
	return 0;
}