#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int N;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	v = vector<int>(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int ans = 0;
	sort(v.begin(), v.end());
	for(int k = N-1; k >= 0 && ans == 0; k--) {
		for(int z = k-1; z >= 0 && ans == 0; z--) {
			int x = 0, y = z;
			while(x <= y && x <= z && ans == 0) {
				int s = v[x] + v[y] + v[z];
				if(s == v[k]) {
					ans = v[k];
				} else if (s > v[k]) {
					y--;
				} else {
					x++;
				}

			}
		}
	}
	cout << ans;
	return 0;
}