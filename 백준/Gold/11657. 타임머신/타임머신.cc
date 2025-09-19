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

int N, M;
vector<pair<int, pair<int, int>>> edges; // weight, start, end

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	int a, b, c;
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edges.push_back({c, {a, b}});
	}
	vector<lld> distance(N+1, INF);
	distance[1] = 0;
	for(int i = 0; i < N-1; i++) {
		for(vector<pair<int, pair<int, int>>>::iterator iter = edges.begin(); iter != edges.end(); iter++) {
			int weight = iter->first;
			int start = iter->second.first;
			int end = iter->second.second;
			if(distance[start] != INF) {
				distance[end] = min(distance[end], distance[start] + weight);
			}
		}
	}
	bool isParadox = false;
	for(vector<pair<int, pair<int, int>>>::iterator iter = edges.begin(); iter != edges.end(); iter++) {
		int weight = iter->first;
		int start = iter->second.first;
		int end = iter->second.second;
		if(distance[start] != INF && distance[end] > distance[start] + weight) {
			distance[end] = distance[start] + weight;
			isParadox = true;
		}
	}
	if(isParadox) {
		cout << "-1\n";
	} else {
		for(int i = 2; i <= N; i++) {
			if(distance[i] == INF) {
				distance[i] = -1;
			}
			cout << distance[i] << '\n';
		}
	}
	return 0;
}