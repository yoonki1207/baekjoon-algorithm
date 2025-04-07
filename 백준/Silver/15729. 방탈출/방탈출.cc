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

int N, cnt;
vector<int> t;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	t = vector<int>(N);
	v = vector<int>(N);
	for(int i = 0; i < N; i++) {
		cin >> t[i];
	}
	for(int i = 0; i < N; i++) {
		if(t[i] != v[i]) {

			cnt++;
			for(int j = i; j < i+3 && j < N; j++) {
				v[j] = (v[j] == 0 ? 1 : 0);
			}
		}
	}
	cout << cnt << endl;

	return 0;
}