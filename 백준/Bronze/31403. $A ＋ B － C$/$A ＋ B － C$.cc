#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int toInteger(string& s) {
	int ret = 0;
	for(int i = 0; i < s.size(); i++) {
		ret *= 10;
		ret += (int)(s[i]-'0');
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	cout << a + b - c << endl;
	string str = to_string(a) + to_string(b);
	cout << toInteger(str)-c << endl;
	return 0;
}