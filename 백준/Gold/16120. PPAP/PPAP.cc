#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    string s;
    vector<char> v;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        v.push_back(s[i]);
        if(v.size() >= 4) {
            int n = v.size();
            if(v[n-1]=='P' && v[n-2]=='A' && v[n-3]=='P' && v[n-4]=='P') {
                v.pop_back();
                v.pop_back();
                v.pop_back();
            }
        }
    }
    if(v.size() == 1 && v[0] == 'P') {
        cout << "PPAP" << endl;
    } else {
        cout << "NP" << endl;
    }
    return 0;
}
/*
P
PPAP
PPAPPAP
PPPAPAP
PPAPPPAPAP
PPAPPAPPAPPAP
PPPAPAP
*/