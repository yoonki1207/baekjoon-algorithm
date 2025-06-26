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

int N;

int main()
{
	int T;
	cin >> T;
	while(T-->0) {
		int n;
		cin >> n;
		int K = 0;
		for(int i = 0; i < n; i++) {
			char a, b;
			cin >> a >> b;
			if((a == 'R' && b == 'P') || (a == 'P' && b == 'S') || (a == 'S' && b == 'R')) K++;
			else if (a == b){}
			else K--;
		}
		if(K>0) {
			cout << "Player 2\n";
		} else if (K <0) {
			cout << "Player 1\n";
		} else {
			cout << "TIE\n";
		}
	}
	return 0;
}
