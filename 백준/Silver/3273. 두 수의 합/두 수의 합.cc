#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int N, X;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> N;
	vector<int> v(N);
	for(int i = 0; i < N; i++) cin >> v[i];
	cin >> X;
	sort(v.begin(), v.end());
	int left = 0, right = N-1, ans = 0;
	while(left < right) {
		int val = v[left] + v[right];
		if(val > X) {
			right--;
		} else if (val < X) {
			left++;
		} else {
			ans++;
			left++;
		}
	}
	cout << ans << endl;
	
	return 0;
}