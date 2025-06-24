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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		if(x < y) {
			cout << "NO BRAINS\n";
		} else {
			cout << "MMM BRAINS\n";
		}
	}
	return 0;
}

// 가정 1: 만약 sigma(si) = N-1이라면 답은 항상 존재하는가?
// 그런데 첫 제출은 항상 맞았습니다. 이다. 그렇다면 0이 필수적이다.

/*
5
0 0 4 0 0
1 3 2 3 4 3 5 3 3
*/
