#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    string s;
    int arr[26]={0};
    cin >> s;
    for(int i = 0; i < s.size(); i++) arr[s[i]-'a']++;
    for(int i = 0; i < 26; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}