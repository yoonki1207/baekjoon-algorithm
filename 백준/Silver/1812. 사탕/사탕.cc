#include <iostream>
#include <vector>

#define lld long long int

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    lld s = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        s += v[i];
    }
    s/=2;
    for(int i = 0; i < n; i++) {
        int x = 0;
        for(int j = 1; j < n; j+=2) {
            x += v[(i+j)%n];
            // cout << j << ' ';
        }
        // cout << endl;
        cout << s-x<<endl;
    }
    return 0;
}

/*
a b c d e
1 3 4 2 5
a+b, b+c, c+d, d+e, a+e
4 7 6 7 6
2(a + b + c + d + e)
b+c + c+d + d+e = a bb cc dd e


*/