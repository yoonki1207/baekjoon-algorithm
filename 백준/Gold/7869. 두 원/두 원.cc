#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int N, M, X;
vector<vector<int>> v;
vector<bool> visited;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	double x1, y1, r1, t1, x2, y2, r2, t2, d, result;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	if(r1+r2 <= d) {
		result = 0.0;
	} else if (fabs(r1-r2) >= d) {
		result = M_PI * fmin(r1 * r1, r2*r2);
	} else {
		t1 = acos((d*d+r1*r1-r2*r2)/(2.0*d*r1))*2.0;
		t2 = acos((d*d+r2*r2-r1*r1)/(2.0*d*r2))*2.0;
		result = (r1*r1*(t1-sin(t1))+r2*r2*(t2-sin(t2)))*0.5;
	}
	printf("%.3lf\n", result);
	return 0;
}