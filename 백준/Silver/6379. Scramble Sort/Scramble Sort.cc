#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

vector<string> split(const string& s, const string& delimeter) {
	string _s = s;
	vector<string> tokens;
	size_t pos = 0;
	string token;
	while ((pos = _s.find(delimeter)) != string::npos) {
		token = _s.substr(0, pos);
		tokens.push_back(token);
		_s.erase(0, pos + delimeter.length());
	}
	tokens.push_back(_s);
	return tokens;
}

bool isNumber(const string& s) {
	bool ret = false;
	int index = 0;
	if (s[0] == '-') {
		index = 1;
		if (s.size() == 1) return false;
	}
	for (; index < s.size(); index++) {
		if (s[index] < '0' || s[index] > '9') return false;
	}
	return true;
}

bool customCompare(const string& a, const string& b) {
	size_t len = min(a.size(), b.size());
	for (int i = 0; i < len; i++) {
		if (tolower(a[i]) == tolower(b[i])) {
			continue;
		}
		else {
			return tolower(a[i]) < tolower(b[i]);
		}
	}
	return a < b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	const string delimeter = ", ";
	while (true) {
		getline(cin, s);
		if (s.compare(".") == 0) break;
		vector<string> tokens = split(s, delimeter);
		string b = tokens.back().substr(0, tokens.back().size() - 1);
		tokens.pop_back();
		tokens.push_back(b);
		vector<int> nrr;
		vector<string> arr;
		vector<bool> index;
		int ni = 0, ai = 0;
		for (int i = 0; i < tokens.size(); i++) {
			int x = 0;
			if(isNumber(tokens[i])) {
				x = stoi(tokens[i]);
				nrr.push_back(x);
				index.push_back(true);
			}
			else {
				arr.push_back(tokens[i]);
				index.push_back(false);
			}
			
		}
		sort(nrr.begin(), nrr.end());
		sort(arr.begin(), arr.end(), customCompare);
		for (int i = 0; i < tokens.size(); i++) {
			if (index[i]) {
				cout << nrr[ni++];
			}
			else {
				cout << arr[ai++];
			}
			if(i != tokens.size()-1) cout << ", ";
		}
		cout << ".\n";

	}

	return 0;
}