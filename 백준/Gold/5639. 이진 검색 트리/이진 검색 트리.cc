#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#define lld long long int
#define MAX_N 10000002

using namespace std;

void postorder(const vector<int>& v, int l, int r) {
	int key = v[l];
	if(r == l) return;
	if(r - l == 1) {
		cout << key << '\n';
		return;
	}
	int index = l+1;
	while(index < r && v[index] < key) {
		index++;
	}
	postorder(v, l+1, index);
	postorder(v, index, r);
	cout << key << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	vector<int> v;
	while(true) {
		int x; cin >> x; 
		if(cin.eof()) break;
		v.push_back(x);
	}
	postorder(v, 0, v.size());
	return 0;
}