#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[2501];
int len = 0;

bool check_max_palindrome(const char* s, int start, int end) { // start와 end를 포함하는 
    bool ret = true;
    for(int i = start; i <= (start + end) / 2; i++)
        if(s[i] != s[end - i + start]) ret = false;
    return ret;
}

int solve(char* s, int start) {
    int ans = 987654321;
    if(start >= len) return 0;
    if(dp[start]) return dp[start];
    int ret = 0;
    for(int i = start; i < len; i++) {
        if(check_max_palindrome(s, start, i)) {
            ret = solve(s, i + 1);
            ans = min(ans, ret + 1);
        }
    }
    return dp[start] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char s[2501];
    cin >> s;
    while(s[len])len++;
    cout << solve(s, 0);
}