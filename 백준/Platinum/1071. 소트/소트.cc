#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#define INF 987654321
#define lld long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n;
int arr[50];
/**
 * if (arr[i]+1 == arr[i+1]) then 
 *   find arr[j] != arr[i+1] (j>i+1)
 *     if j exist then swap and sort
 *     else swap(arr[i], arr[i+1]) and i--
 */

bool solve(int* arr, int n) {
	int index = 0;
	while(index < n) {
		if(arr[index]+1 == arr[index+1]) {
			bool isSwapped = false;
			for(int j = index+2; j < n; j++) {
				if(arr[index+1] < arr[j]) {
					swap(arr[index+1], arr[j]);
					isSwapped = true;
					break;
				}
			}
			if(!isSwapped && index + 1 < n) {
				swap(arr[index], arr[index+1]);
				index = -1;
			}
		}
		index++;
	}
	return true;
}

bool isAns(int* arr, int n) {
	for(int i = 0; i < n-1; i++)if(arr[i]+1 == arr[i+1]) return false;
	return true;
}

int main() {
	FAST_IO
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// n = 50;
	// for(int i = 0; i < n; i++) arr[i] = i+1;
	sort(arr, arr+n);
	solve(arr, n);
	for(int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}
/**

1 1 2 2
1 1 2 2
2 2 1 1
0 1 2 3 4
1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
1 2 5 3 4
1 2 5 4 3
1 3 2 4 5
1 3 2 5 4
1 3 4 2 5
1 3 4 5 2
1 3 5 2 4
1 3 5 4 2
1 4 2 3 5

 */