#include <iostream>
#include <iomanip>
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

int n;
double arr[100][100];
vector<pair<double, double>> v;

int parent[101];

int getParent(int a) {
	if(parent[a] != a) return parent[a] = getParent(parent[a]);
	return parent[a];
}

void unionParent(int a, int b) {
	int pa = getParent(a);
	int pb = getParent(b);
	if(pa != pb) parent[pb] = pa;
}


double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

double sqrdistance(double x1, double y1, double x2, double y2) {
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	for(int i = 0; i < 101; i++) parent[i] = i;
	cin >> n;
	v = vector<pair<double, double>>(n);
	
	for(int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		v[i].first = x;
		v[i].second = y;
	}
	priority_queue<pair<double, pair<int, int>>> pq;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			double d = sqrdistance(v[i].first, v[i].second, v[j].first, v[j].second);
			pq.push({-d, {i, j}});
		}
	}
	int k = n - 1;
	double ans = 0.0;
	while(!pq.empty() && k > 0){
		double d = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();
		if(getParent(a) != getParent(b)) {
			k--;
			ans += sqrt(d);
			unionParent(a, b);
		}
	}

	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}