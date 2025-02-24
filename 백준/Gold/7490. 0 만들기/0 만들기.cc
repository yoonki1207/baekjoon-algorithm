#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321

using namespace std;

int T, N;
vector<char> v;

int calc(int index) {
    string s = "";
    for(int i = 0; i < v.size(); i++) if(v[i] != ' ') s += v[i];
    vector<int> ret;
    vector<char> op;
    int n = 0;
    for(int i = 0; i < s.size(); i++) {

        if(s[i] == '+' || s[i] == '-') {
            ret.push_back(n);
            op.push_back(s[i]);
            n = 0;
        } else {
            n = n*10 + (int)(s[i]-'0');
        }
    }
    if(n != 0) ret.push_back(n);
    int r = ret[0];
    for(int i = 0; i < op.size(); i++) {
        if(op[i] == '+') {
            r = r + ret[i+1];
        } else {
            r = r - ret[i+1];
        }
    }
    return r;
}

void solve(int n) {
	if (n == N) {
		v.push_back((char)(n + '0'));
		int result = 0;
		int number = 0;
		if (calc(0) == 0) {
			//cout << calc(0) << ": ";
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			} cout << '\n';
		}
		v.pop_back();
		return;
	}

	v.push_back((char)(n + '0'));

	v.push_back(' ');
	solve(n + 1);
	v.pop_back();

	v.push_back('+');
	solve(n + 1);
	v.pop_back();

	v.push_back('-');
	solve(n + 1);
	v.pop_back();

	v.pop_back();
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		v = vector<char>();
		solve(1);
		cout << '\n';
	}
	return 0;
}