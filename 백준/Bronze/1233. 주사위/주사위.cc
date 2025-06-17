#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321
#define lld long long
#define ull unsigned long long
#define MAX_N 500000

using namespace std;

int freq[16001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	for(int i = 1; i <= a; i++) {
		for(int j = 1; j <= b; j++) {
			for(int k = 1; k <= c; k++) {
				freq[i+j+k]++;
			}
		}
	}
	int max_n = 0;
	for(int i = 0; i < 16001; i++) {
		max_n = max(max_n, freq[i]);
	}
	for(int i = 0; i < 16001; i++) {
		if(freq[i] == max_n) {
			cout << i;
			break;
		}
	}
	return 0;
}
