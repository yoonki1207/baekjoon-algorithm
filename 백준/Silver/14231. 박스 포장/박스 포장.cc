#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int N; 
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> N;
	v = vector<int>(N);
	for(int i = 0; i < N; i++) {
		cin >> v[i];
	}
	vector<int> arr;
	for(int i = 0; i < N; i++) {
		auto iter = lower_bound(arr.begin(), arr.end(), v[i]);
		if(iter == arr.end()) arr.push_back(v[i]);
		else *iter = v[i];
	}
	cout << arr.size();

	return 0;
}