#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int N; // 100,000
vector<int> arr;
vector<int> brr;
int cnt;

// 000
// 010

void press(int index) {
	if(index == 0) {
		arr[0] = !arr[0];
		arr[1] = !arr[1];
	} else if (index == N-1) {
		arr[N-1] = !arr[N-1];
		arr[N-2] = !arr[N-1];
	} else {
		arr[index-1] = !arr[index-1];
		arr[index] = !arr[index];
		arr[index+1] = !arr[index+1];
	}
	cnt++;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> N;
	arr = vector<int>(N);
	brr = vector<int>(N);
	string s;
	cin >> s;
	for(int i = 0; i < N; i++) arr[i] = s[i] == '0' ? 0 : 1;
	cin >> s;
	for(int i = 0; i < N; i++) brr[i] = s[i] == '0' ? 0 : 1;
	vector<int> tmp = arr;
	
	// press index 0
	int ans = INF;
	cnt = 0;
	press(0);
	if(arr[0] != brr[0]) press(1);
	for(int i = 2; i < N; i++) {
		if(arr[i-1] != brr[i-1]) press(i);
	}
	if(arr[N-1] != brr[N-1]) cnt = -1;
	ans = cnt;
	// not press
	for(int i = 0; i < N; i++) arr[i] = tmp[i];
	cnt = 0;
	if(arr[0] != brr[0]) press(1);
	for(int i = 2; i < N; i++) {
		if(arr[i-1] != brr[i-1]) press(i);
	}
	if(arr[N-1] != brr[N-1]) cnt = -1;
	if(ans == -1) ans = cnt;
	else ans = min(ans, cnt < 0 ? INF : cnt);
	cout << ans;
	return 0;
}