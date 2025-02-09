#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

bool cache[600000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 100000;
    cin >> n;
    int a = 0;
    cache[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(a - i < 0 || cache[a-i]) {
            a = a + i;
        } else {
            a = a - i;
        }
        cache[a] = 1;
    }
    cout << a << endl;
    return 0;
}