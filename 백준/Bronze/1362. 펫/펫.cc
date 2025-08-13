#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int sinario = 1;
	while(true) {
		int target_weight, weight;
		cin >> target_weight >> weight;
		if(target_weight == 0 && weight == 0) break;
		while(true) {
			string s;
			int n;
			cin >> s >> n;
			if(s.compare("#") == 0 && n == 0) break;
			if(weight <= 0) continue;
			if(s.compare("F") == 0) weight += n;
			else if (s.compare("E") == 0) weight -= n;
		}
		string res;
		if(weight <= 0) res = "RIP";
		else if (weight > target_weight/2 && weight < target_weight*2) res = ":-)";
		else res = ":-(";
		cout << sinario++ << ' ' << res << '\n';
	}
	return 0;
}