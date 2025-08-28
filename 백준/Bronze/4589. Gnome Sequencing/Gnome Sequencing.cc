#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

int main() {
    fast;
    int t;
    cin >> t;
    cout << "Gnomes:\n";
    while(t--){
        vector <int> lst(3);
        for(int i = 0; i < 3; i++) cin >> lst[i];
        if ((lst[1] - lst[0]) * (lst[2] - lst[1]) > 0) cout << "Ordered\n";
        else cout << "Unordered\n";
    }
}