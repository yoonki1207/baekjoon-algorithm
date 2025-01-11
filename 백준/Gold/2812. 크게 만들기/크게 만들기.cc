#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX_N 2000001
#define lld long long int

using namespace std;

int arr[500000];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++) arr[i] = (int)(s[i]-'0');
	vector<int> v;
	v.push_back(arr[0]);
	int index = 1;
	while(index < s.size() && k > 0) {
		while(!v.empty() && v.back() < arr[index] && k > 0) {
			// cout << "k: " << k << endl;
			v.pop_back(); k--;
		}
		v.push_back(arr[index]);
		
		index++;
	}
	while(index < s.size()) v.push_back(arr[index++]);
	while(k>0) {
		v.pop_back();
		k--;
	}
	// cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++) cout << v[i];
	return 0;
}
// 1231234 - 3 - 3234
// 1239234 - 3 - 9234
// 5432123 - 3 - 5432