#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321

using namespace std;

int isPalindrome(string s) {
    int ret = -1;
    for(int i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size()-i-1]) return i;
    }
    return -1;
}

int solve(string s) {
    int ret = isPalindrome(s);
    // cout << ret << endl;
    if(ret == -1) return 0;
    int i = 0, j = s.size()-1;
    bool a = true;
    bool b = true;
    while(i < j) {
        if(ret == i) i++;
        if(s[i] != s[j]) a = false;
        i++; 
        j--; 
    }
    i = 0; j = s.size()-1;
    while(i < j) {
        if(s.size()-1-ret == j) j--;
        if(s[i] != s[j]) b = false;
        i++; 
        j--; 
    }
    if(a||b) return 1;
    return 2;
}

int main()
{
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
    return 0;
}

/*
summuus
suummus

su_muus
suum_us

summ_us
su_mmus

*/