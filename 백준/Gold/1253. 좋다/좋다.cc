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

int N;
vector<int> v;
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	v = vector<int>(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		int pivot = v[i];
		int left = 0, right = N-1;
		while(left < right) {
			if(left == i) left++;
			else if(right == i) right--;
			else if(v[left] + v[right] > pivot) {
				left++;
			} else if(v[left] + v[right] < pivot) {
				right--;
			} else {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}