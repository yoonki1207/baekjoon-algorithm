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
#define MAX_N 500000

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	while(n-->0) {
		string s;
		cin >> s;
		bool arr[255]={0};
		for(char c: s) {
			arr[(int)c] = true;
		}
		int ans = 0;
		for(char c = 'A'; c <= 'Z'; c++) {
			if(arr[(int)c] == false) {
				ans += (int)c;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
