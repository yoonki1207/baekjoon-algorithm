#include <iostream>
#include <string>
using namespace std;

int main() {
    int n; string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            ans ++;
        }
    }
    cout << ans;
}