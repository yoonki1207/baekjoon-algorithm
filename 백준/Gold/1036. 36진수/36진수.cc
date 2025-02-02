#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const char* crr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int irr[255];

void init() {
    for (char c = '0'; c <= '9'; c++) irr[c] = c - '0';
    for (char c = 'A'; c <= 'Z'; c++) irr[c] = c - 'A'+10;
}

string add36(const string& a, const string& b) {
    string ret = "";
    int c = 0;
    int i = 0;
    for (i = 0; i < min(a.size(), b.size()); i++) {
        if (a.size() <= i || b.size() <= i) break;
        char ac = a[a.size() - i - 1];
        char bc = b[b.size() - i - 1];
        int val = irr[ac] + irr[bc] + c;
        c = val / 36;
        val = val % 36;
        ret = crr[val] + ret;
    }
    while (a.size() > i) {
        char ac = a[a.size() - i - 1];
        int val = irr[ac] + c;
        c = val / 36;
        val = val % 36;
        ret = crr[val] + ret;
        i++;
    }
    while (b.size() > i) {
        char bc = b[b.size() - i - 1];
        int val = irr[bc] + c;
        c = val / 36;
        val = val % 36;
        ret = crr[val] + ret;
        i++;
    }
    if (c) {
        ret = "1" + ret;
    }
    return ret;
}

string mul36(const string& a, int n) {
    string ret = "0";
    if (n == 0) return ret;
    if (n == 1) return a;
    if (a.compare("0") != 0 && n == 36) {
        return a + "0";
    }
    string s = mul36(a, n / 2);
    if (n % 2 == 0) {
        ret = add36(s, s);
    }
    else {
        ret = add36(s, s);
        ret = add36(ret, a);
    }
    return ret;
}

string brw(string& s, const int n) {
	int k = irr[s[n]] - 1;
	if(k < 0) {
		k += 36;
		brw(s, n-1);
	}
	s[n] = crr[k];
	// if(n==0&&ret[0]=='0') return ret.substr(1);
	return s;
}

string sub36(const string& _a, const string& b) { // a > b
	string ret = "";
	string a = _a;
    int i=0;
	for(i = 0; i < b.size(); i++) {
		char ca = a[a.size()-i-1];
		char cb = b[b.size()-i-1];
		int k = irr[ca]-irr[cb];
		if(k<0){
			a = brw(a, a.size()-i-2);
            k += 36;
		}
        ret = crr[k] + ret;
	}
    for(;i<a.size();i++){
        ret = a[a.size()-i-1] + ret;
    }
    int zeroIndex = 0;
    while(ret[zeroIndex] == '0' && zeroIndex + 1 < ret.size()) {
        zeroIndex++;
    }
    return ret.substr(zeroIndex);
}

bool customSort(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.first.size() == b.first.size()) {
        return a.first > b.first;
    }
    else {
        return a.first.size() > b.first.size();
    }
}

void solve(vector<string>& s, int k) {
    vector<vector<int>> v(36); // 36*50 = 180 (180*4bytes = 720bytes)
    for (int i = 0; i < 36; i++) {
        vector<int> tmp(50, 0);
        v[i] = tmp;
    }
    for (vector<string>::iterator iter = s.begin();
        iter != s.end(); ++iter) {
        for (int i = 0; i < iter->size(); i++) {
            int value = irr[(*iter)[iter->size()-i-1]];
            v[value][i]++;
        }
    }

    vector<string> num36(36);
    vector<string> diff36(36);
    vector<string> origin36(36);
    for (int i = 0; i < 36; i++) {
        string c = "0";
        string o = "0";
        for (int j = 0; j < 50; j++) {
            c = mul36(c, 36);
            o = mul36(o, 36);
            string ctt(1, crr[i]);
            c = add36(c, mul36("Z", v[i][50 - j - 1]));
            o = add36(o, mul36(ctt, v[i][50 - j - 1]));
        }
        num36[i] = c;
        origin36[i] = o;
        diff36[i] = sub36(c, o);
    }
    vector<pair<string, int>> map36(36);
    for (int i = 0; i < 36; i++) {
        map36[i] = { diff36[i], i };
    }
    sort(map36.begin(), map36.end(), customSort);

    string ans = "0";
    vector<int> vc;
    int j = 0;
    for (int i = 0; i < 36; i++) {
        if (j < k) {
            ans = add36(ans, num36[map36[i].second]);
            j++;
        }
        else {
            int c = map36[i].second;
            ans = add36(ans, origin36[c]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    init();
    // TODO: solve 1036
    int n, k;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    cin >> k;
    solve(s, k);
    return 0;
}