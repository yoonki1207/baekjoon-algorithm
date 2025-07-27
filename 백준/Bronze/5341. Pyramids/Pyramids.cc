#include<iostream>

using namespace std;

int main() {
    while(true) {
        int x;
        cin >> x;
        if(x == 0) break;
        int res = x*(x+1)/2;
        cout << res << '\n';
    }
    return 0;
}