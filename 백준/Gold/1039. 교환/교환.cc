#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#define INF 987654321
#define MAX_N 1503
#define lld long long
#define pii pair<int, int>

using namespace std;

// 백준 
int N, K;
int ans;
vector<int> v;

vector<pair<pair<int, int>, int>> test_case = {
			{{1, 1}, -1},
			{{1, 10}, -1},
			{{10, 1}, -1},
			{{10, 2}, -1},
			{{12, 2}, 12},
			{{100, 1}, 100},
			{{100, 5}, 100},
			{{1000000, 10}, 1000000},
			{{210, 1}, 201},
			{{1220, 2}, 2210},
			{{135745, 5}, 755431},
			{{135745, 6}, 755431},
			{{135745, 7}, 755431},
			{{404, 1}, 440},
			{{404, 2}, 440},
			{{4040, 1}, 4400},
			{{4040, 2}, 4400},
			{{4044, 1}, 4440},
			{{4044, 2}, 4440},
			{{8404, 1}, 8440},
			{{8404, 2}, 8440},
			{{3404, 1}, 4403},
			{{3404, 2}, 4430},
			{{3404, 3}, 4430},
			{{199, 1}, 991},
			{{8799, 2}, 9987},
			{{123444, 3}, 444321},
			{{213444, 3}, 444321},
			{{321444, 3}, 444321},
			{{123444, 4}, 444321},
			{{123455, 1}, 523451},
			{{123455, 2}, 553421},
			{{123455, 3}, 554321},
			{{123455, 4}, 554321},
			{{123455, 5}, 554321},
			{{123455, 6}, 554321},
			{{789432, 10}, 987423},
			{{421888, 3}, 888421},
			{{999299, 1}, 999992},
			{{999299, 2}, 999992},
			{{929292, 1}, 999222},
			{{929292, 2}, 999222},
			{{929292, 3}, 999222},
			{{123456, 1}, 623451},
			{{123456, 2}, 653421},
			{{123456, 3}, 654321},
			{{123456, 4}, 654312},
			{{123456, 5}, 654321},
			{{381993, 3}, 998133},
			{{12344, 2}, 44321} };

void init() {
	int tmp = N;
	vector<int> tmpv;
	while (tmp > 0) {
		tmpv.push_back(tmp % 10);
		tmp /= 10;
	}
	while (!tmpv.empty()) {
		v.push_back(tmpv.back());
		tmpv.pop_back();
	}
}

void test() {
	int solve();
	for (int i = 0; i < test_case.size(); i++) {
		int _N = test_case[i].first.first;
		int _K = test_case[i].first.second;
		N = _N;
		K = _K;
		int A = test_case[i].second;
		v.clear();
		ans = 0;
		ans = solve();
		if (A != ans) {
			cout << "Input " << _N << ' ' << _K << " must return " << A <<
				", but program returns " << ans << endl;
		}
	}
}

void input() {
	cin >> N >> K;
}

void reorder(vector<int> origin) {
	/*for (int i = 0; i < origin.size(); i++) {
		cout << origin[i] << ' ';
	} cout << endl;
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << ' ';
	}cout << endl;*/
	for (int i = 0; i < 10; i++) {
		vector<int> tmp;
		vector<int> index;
		for (int j = 0; j < origin.size(); j++) {
			if (origin[j] == i) {
				tmp.push_back(v[j]);
				index.push_back(j);
			}
		}
		sort(tmp.begin(), tmp.end(), greater<int>());
		for (int j = 0; j < tmp.size(); j++) {
			v[index[j]] = tmp[j];
		}
	}
}

int solve() {
	init();
	int index = 0;
	if (N <= 10) ans = -1;
	else if (N < 100) {
		if (N % 10 == 0) ans = -1;
		else {
			if (K % 2 == 1) {
				swap(v[0], v[1]);
				K = 0;
			}
		}
	}
	vector<int> origin_v = v;
	while (K > 0 && ans != -1) {
		if (index >= v.size() - 1) {
			reorder(origin_v);
			bool breakable = false;
			for (int i = 0; i < v.size() - 1; i++) {
				if (v[i] == v[i + 1]) breakable = true;
			}
			if (breakable) break;
			index = v.size() - 1;
			if (K % 2 == 1) {
				swap(v[index - 1], v[index]);
			}
			break;
		}
		int max_val = v[index];
		int max_index = index;
		// 오른쪽 중 가장 큰 값을 찾는다.
		for (int i = index + 1; i < v.size(); i++) {
			if (v[i] >= max_val) {
				max_val = v[i];
				max_index = i;
			}
		}
		if (max_val <= v[index]) { // 굳이 바꿀 필요가 없다면
			index++; // 다음인덱스 탐색
		}
		else { // 바꿔야한다면
			swap(v[index], v[max_index]);
			index++;
			K--;
		}
	}
	if (ans == -1) {
		//cout << ans;
		return ans;
	}
	else {
		ans = 0;
		reorder(origin_v);
		for (int i = 0; i < v.size(); i++) {
			ans *= 10;
			ans += v[i];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	//test();
	input();
	ans = solve();
	cout << ans << endl;

	return 0;
}

/*
436659
936654
966354

1220
2210
2210

왼쪽 자릿수부터
본인보다 오른쪽 자리에서 0이아닌 가장 큰 수와 바꾼다.

132
312
321


135745 5

735145
755143
755413
755431
755431

8799
9798
9978

32995 2
92935
99235

99325

5489 2
9485
9845

같은 숫자가 중복해있으면 어떤 숫자와로도 바꿀 수 있다.
즉, 8799가 9978로 바뀌었다면, 9987또한 가능하다는 이야기.
7과 8 둘 다 9와 바꿨으니 서로를 바꿔도 아무런 손해가 아니다.
즉, 변경되기 전 자리에있던 숫자를 담는 변수를 하나 더 만들어서
한번 더 오름차순 정렬을 하면 해결될 일이다.

3155
5153
5513

10032 2
30012
32010

381993 3 : 998133
981933
991833
998133

981393
991383
998313


998313

*/