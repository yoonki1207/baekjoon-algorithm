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

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	while(true) {
		int x, index = 0, ans = 0;
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		vector<int> v(N);
		for(int i = 0; i < N; i++) {
			cin >> v[i];
		}
		for(int i = 0; i < M; i++) {
			cin >> x;
			while(index < N && v[index] < x) ++index;
			if(v[index] == x) ans++;
		}
		cout << ans << '\n';
	}
	
	return 0;
}