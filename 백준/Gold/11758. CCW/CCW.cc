#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	int arr[3][2] = {0};
	for(int i = 0; i < 3; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	int x = arr[1][0] - arr[0][0];
	int y = arr[1][1] - arr[0][1];
	int a = arr[2][0] - arr[0][0];
	int b = arr[2][1] - arr[0][1];
	int p = x*b - y*a;
	int ans = p == 0 ? 0 : p > 0 ? 1 : -1;
	cout << ans << endl;
	return 0;
}