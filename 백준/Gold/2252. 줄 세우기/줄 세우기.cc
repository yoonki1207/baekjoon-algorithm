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
#define MAX_N 32001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

// topoligical sort

int N, M, a, b; // N = 32000
vector<vector<int>> v;
vector<int> degree;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	v = vector<vector<int>>(N+1);
	degree = vector<int>(N+1);
	for(int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		degree[b]++;
	}
	queue<int> t;
	for(int i = 1; i <= N; i++) {
		if(degree[i] == 0) t.push(i);
	}

	while(!t.empty()) {
		int front = t.front();
		cout << front << ' ';
		t.pop();
		for(int i = 0; i < v[front].size(); i++) {
			int next = v[front][i];
			if((--degree[next]) == 0) {
				t.push(next);
			}
		}
	}
	return 0;
}