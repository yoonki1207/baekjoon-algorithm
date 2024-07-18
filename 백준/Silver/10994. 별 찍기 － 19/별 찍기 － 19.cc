#include <iostream>
#include <vector>

using namespace std;

int n;

void printStars(int n, int m) {
    if(n == 1) {
        cout << '*';
        return;
    }
    int len = n*4 - 3;
    if(m == 0 || m == len-1) {
        for(int i = 0; i < len; i++) cout << '*';
    } else if (m == 1 || m == len - 2) {
        cout << '*';
        for(int i = 0; i < len - 2; i++) cout << ' ';
        cout << "*";
    } else {
        cout << "* ";
        printStars(n-1, m-2);
        cout << " *";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n * 4 - 3; i++) {
        printStars(n, i);
        cout << '\n';
    }
    return 0;
}