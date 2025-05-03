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

int arr[MAX_N];

bool customCompare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> mat(1000001);
	vector<int> result(n);
	for(int i = 0; i < n; i++) {	
		int x; cin >> x;
		v[i] = x;
	}
	for (size_t i = 0; i < n; i++)
	{
		mat[v[i]]++;
	}
	
	for(int i = 0; i < n; i++) {
		int t = 1;
		while(t*t <= v[i]) {
			if(v[i] % t == 0) {
				if(t*t != v[i]) {
					result[i] += mat[t] + mat[(int)(v[i]/t)];
				} else {
					result[i] += mat[t];
				}
			}
			t++;
		}
	}

	for(int i = 0; i < n; i++) {
		cout << result[i]-1 << '\n';
	}

	return 0;
}