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

int X, Y, D, T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> X >> Y >> D >> T;
	double distance = sqrt(X*X+Y*Y);
	// if T/D < 1 then do not
	int nJump = distance / D; // 초과하지 않고 직선으로의 최대 점프 횟수
	double left = distance - (double)nJump * D; // 했을 때 남은 거리
	double ans = 0;
	if(nJump == 0) { // 점프를 못 했으면
		// 점프 두 번, 걸어가기, 점프 한 번 + 뒤로가기의 시간 비교
		ans = min((double)T*2, min(left, T+(D-distance)));
	} else { // 점프를 했으면
		// 점프 한 번 더(두번효과), 남은거리 걸어가기
		ans = min((double)(nJump+1)*T, left + nJump*T);
		ans = min(ans, distance);
	}
	cout.precision(13);
	cout << fixed;
	cout << ans;
	return 0;
}