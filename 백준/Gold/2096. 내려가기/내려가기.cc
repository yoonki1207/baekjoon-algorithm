#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#define lld long long int
#define MAX_N 10000002

using namespace std;

int arr[100000][3];
int dpmax[2][3];
int dpmin[2][3];


int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	dpmax[0][0] = arr[0][0]; dpmax[0][1] = arr[0][1]; dpmax[0][2] = arr[0][2];
	dpmin[0][0] = arr[0][0]; dpmin[0][1] = arr[0][1]; dpmin[0][2] = arr[0][2];
	for(int i = 1; i < n; i++) {
		dpmax[i%2][0] = max(dpmax[(i-1)%2][0], dpmax[(i-1)%2][1]) + arr[i][0];
		dpmax[i%2][1] = max(dpmax[(i-1)%2][0], max(dpmax[(i-1)%2][1], dpmax[(i-1)%2][2])) + arr[i][1];
		dpmax[i%2][2] = max(dpmax[(i-1)%2][1], dpmax[(i-1)%2][2]) + arr[i][2];

		dpmin[i%2][0] = min(dpmin[(i-1)%2][0], dpmin[(i-1)%2][1]) + arr[i][0];
		dpmin[i%2][1] = min(dpmin[(i-1)%2][0], min(dpmin[(i-1)%2][1], dpmin[(i-1)%2][2])) + arr[i][1];
		dpmin[i%2][2] = min(dpmin[(i-1)%2][1], dpmin[(i-1)%2][2]) + arr[i][2];
	}
	cout << max(dpmax[(n-1)%2][0], max(dpmax[(n-1)%2][1], dpmax[(n-1)%2][2])) << ' ';
	cout << min(dpmin[(n-1)%2][0], min(dpmin[(n-1)%2][1], dpmin[(n-1)%2][2])) << endl;
	return 0;
}