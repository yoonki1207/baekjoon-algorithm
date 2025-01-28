#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#define INF 987654321
#define lld long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int arr[401][401];

// int n, k;

int main() {
	FAST_IO
	int n;
	cin >> n;
	int x = 3;
	for(int i = 2; i <= n; i++) {
		x += i*(i+1)+i*(i+1)/2;
	}
	cout << x;
	return 0;
}