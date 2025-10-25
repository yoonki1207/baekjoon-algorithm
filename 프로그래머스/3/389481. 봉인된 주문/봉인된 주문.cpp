#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define lld long long

using namespace std;

lld getIndex(string s) {
    lld ret = 0;
    for(int i = 0; i < s.size(); i++) {
        int d = s[i]-'a'+1;
        ret *= 26;
        ret += (lld)d;
    }
    return ret;
}

string getString(lld index) {
    string ret = "";
    while(index > 0) {
        char c = (index - 1) % 26 + 'a';
        ret = c + ret;
        index = (index - 1) / 26;
    }
    return ret;
}

string solution(long long n, vector<string> bans) {
    string answer = "";
    vector<lld> nBans;
    for(int i = 0; i < bans.size(); i++) {
        lld index = getIndex(bans[i]);
        nBans.push_back(index);
    }
    sort(nBans.begin(), nBans.end());
    for(int i = 0; i < nBans.size(); i++) {
        lld index = nBans[i];
        if(index <= n) {
            n++;
        } else {
            break;
        }
    }
    // cout << getString(26*26 + 1) << ' ' << getIndex("azz") << endl;
    // cout << getIndex("za") << endl;
    
    return getString(n);
}

/*
12345678901234567890123456
abcdefghijklmnopqrstuvwxyz

aa = 26 + 1
ba = 26*2 + 1
za = 26*26 + 1

TODO: Problem - int to string occur error
*/