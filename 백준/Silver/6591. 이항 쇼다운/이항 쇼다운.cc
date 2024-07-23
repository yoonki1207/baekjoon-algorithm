#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAX_N 1000

using namespace std;

unsigned int a, b;
unsigned int cache[MAX_N][MAX_N/2];
unsigned int comb(unsigned int n, unsigned int r) {
    if(r > n/2) r = n - r;
    if(n <= 1 || r == 0) return 1;
    if(r == 1) return n;
    if(n >= MAX_N || r >= MAX_N) {
        return comb(n - 1, r - 1) + comb(n - 1, r);
    }
    
    unsigned int& ret = cache[n][r];
    if(ret) return ret;

    return ret = comb(n - 1, r - 1) + comb(n - 1, r);
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    while(true) {
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        unsigned int ret = comb(a, b);
        cout << ret << endl;
    }
    return 0;
}