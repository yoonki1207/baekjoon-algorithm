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
#define ull unsigned long long
#define MAX_N 1000001

using namespace std;

map<string, bool> visitedSet;

void swapping(double& a, double& b, double& c, double& d) {
	double t = a;
	a = c;
	c = d;
	d = b;
	b = t;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = 0;
	double max_n = (a*d+c*b)/(c*d);
	
	swapping(a, b, c, d);
	if(max_n < (a*d+c*b)/(c*d)) {
		max_n = (a*d+c*b)/(c*d);
		ans = 1;
	}
	
	swapping(a, b, c, d);
	if(max_n < (a*d+c*b)/(c*d)) {
		max_n = (a*d+c*b)/(c*d);
		ans = 2;
	}
	

	swapping(a, b, c, d);
	if(max_n < (a*d+c*b)/(c*d)) {
		max_n = (a*d+c*b)/(c*d);
		ans = 3;
	}
	
	cout << ans << endl;

	
	
	return 0;
}