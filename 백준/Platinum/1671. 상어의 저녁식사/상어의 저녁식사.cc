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
#define MAX_N 51
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

class Shark {
public:
	int size;
	int speed;
	int iq;
	Shark() {size = speed = iq = 0;}
	Shark(int size, int speed, int iq): size(size), speed(speed), iq(iq) {}
	bool canEat(const Shark& other) {
		return size >= other.size &&
		 speed >= other.speed &&
		 iq >= other.iq;
	}
};

int N;
Shark arr[MAX_N];
int slt[MAX_N];
bool done[MAX_N];

bool dfs(int x) {
	Shark& now = arr[x];
	for(int i = 1; i <= N; i++) {
		if(x == i || !now.canEat(arr[i])) continue;
		if (arr[x].size == arr[i].size &&
            arr[x].speed == arr[i].speed &&
            arr[x].iq == arr[i].iq &&
            x > i) continue;
		if(done[i]) continue;
		
		// cout << "Cycle: " << x << " to " << i << " is " << isCycle(x, i) << endl;
		done[i] = true;
		if(slt[i] == 0 || dfs(slt[i])) {
			slt[i] = x;

			// cout << "Match: " << x << " to " << i << endl;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	int a, b, c;
	for(int i = 1; i <= N; i++) {
		cin >> a >> b >> c;
		arr[i] = *(new Shark(a, b, c));
	}
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		fill(done, done+MAX_N, false);
		if(dfs(i)) {
			cnt++;
		}
	}
	for(int i = 1; i <= N; i++) {
		fill(done, done+MAX_N, false);
		if(dfs(i)) {
			cnt++;
		}
	}
	cout << N - cnt;
	return 0;
}

/*
Input:
5
1 2 1
2 1 1
1 1 5
2 2 4
2 2 5
Output:
1

5
2 2 4
2 1 1
1 2 1
2 2 5
1 1 5

5
1 2 1
2 1 1
1 1 2
2 2 4
2 2 4
*/