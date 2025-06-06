#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define INF 987654321

using namespace std;

vector<int> getPi(string p) {
    int m = (int)p.size(), j = 0;
    vector<int> pi(m, 0);
    for(int i = 1; i < m; i++) {
        while(j > 0 && p[i] != p[j]) {
            j = pi[j-1];
        }
        if(p[i] == p[j]) {
            pi[i] = ++j;
        }
    }
    return pi;
}

vector<int> kmp(string s, string p) {
    vector<int> ans;
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j = 0;
    for(int i = 0; i < n; i++) {
        while(j>0 && s[i] != p[j]) {
            j = pi[j-1];
        }
        if(s[i] == p[j]) {
            if(j == m-1) {
                ans.push_back(i-m+1);
                j = pi[j];
            } else {
                j++;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        vector<int> pi = getPi(s.substr(i));
        for(int i = 0; i < pi.size(); i++) ans = max(ans, pi[i]);
    }
    cout << ans << endl;
    return 0;
}