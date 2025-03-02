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
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int a, b;
		cin >> a >> b;
		cout << "Case " << i << ": " << a+b << endl;
	}
	
	return 0;
}

