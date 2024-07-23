#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#define MAX_N 1000

using namespace std;

const char findChar[5] = "UCPC";

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    getline(cin, s);
    int index = 0;
    for(int i = 0; i < s.size(); i++) {
        const char fChar = findChar[index];
        if(fChar == s[i]) {
            index++;
        }
        if(index == 4) {
            break;
        }
    }

    if(index == 4) cout << "I love UCPC\n";
    else cout << "I hate UCPC\n";
    return 0;
}