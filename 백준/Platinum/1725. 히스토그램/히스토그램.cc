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

int n;
vector<int> v;

lld solve(int start, int end) {
	if(start == end) {
		return v[start];
	}
	if(start > end) {
		return 0;
	}

	int mid = (start + end) / 2;
	lld left_area = solve(start, mid);
	lld right_area = solve(mid + 1, end);
	lld mid_area = 0;

	lld max_area = max(left_area, right_area);

	int left = mid;
	int right = mid + 1;
	int height = min(v[left], v[right]);
	mid_area = (right-left+1) * height;
	while(start < left && right < end) {
		if(v[left-1] < v[right+1]) {
			right++;
			height = min(height, v[right]);
		} else {
			left--;
			height = min(height, v[left]);
		}
		lld area = (right-left+1) * height;
		mid_area = max(mid_area, area);
	}

	lld area = 0;
	if(start == left) {
		while(right < end) {
			right++;
			height = min(height, v[right]);
			area = (right-left+1) * height;
			mid_area = max(mid_area, area);
		}
	} else {
		while(left > start) {
			left--;
			height = min(height, v[left]);
			area = (right-left+1) * height;
			mid_area = max(mid_area, area);
		}
	}
	return max(mid_area, max_area);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	v = vector<int>(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	lld ans = solve(0, n-1);
	cout << ans << endl;

	return 0;
}