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

int N, M; // N: 1백만, M: 20억
vector<int> v;

lld getTrees(lld x) {
	vector<int>::iterator lb = lower_bound(v.begin(), v.end(), x);
	lld ret = 0l;
	for(vector<int>::iterator iter = lb; iter != v.end(); iter++) {
		ret += (lld)((*iter) - x);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	v = vector<int>(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	lld left = 0, right = 2000000001;
	int ans = 0;
	while(left < right) {
		lld mid = (left + right) / 2;
		if(getTrees(mid) >= M) {
			ans = left;
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	cout << right - 1  << endl;
	return 0;
}

/*
v는 나무의 높이 배열
v를 오름차순 정렬한다.
절단기의 높이를 x라 정의한다.

def 가져갈 수 있는 나무의 양:
	lower_bound: 절단기
*/