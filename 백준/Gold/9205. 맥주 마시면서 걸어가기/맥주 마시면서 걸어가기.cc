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
#define MAX_N 103
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int T, N;
int arr[MAX_N][2];

inline int manhattan_distance(int x1, int y1, int x2, int y2) {
	return abs(x2-x1) + abs(y2-y1);
}
inline int manhattan_distance(pii a, pii b) {
	return manhattan_distance(a.first, b.first, a.second, b.second);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		for(int i = 0; i < N+2; i++) {
			cin >> arr[i][0] >> arr[i][1];
		}
		queue<pii> q;
		vector<bool> visited(N+2, false);
		q.push({arr[0][0], arr[0][1]});
		visited[0] = true;
		bool isPossible = false;
		while(!q.empty() && !isPossible) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int i = 1; i < N+2; i++) {
				if(!visited[i] && manhattan_distance(x, y, arr[i][0], arr[i][1]) <= 1000) {
					if(i == N+1) {
						isPossible = true;
					}
					q.push({arr[i][0], arr[i][1]});
					visited[i] = true;
				}
			}
		}
		
		if(isPossible) {
			cout << "happy\n";
		} else {
			cout << "sad\n";
		}
	}
	return 0;
}