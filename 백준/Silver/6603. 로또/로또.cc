#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    while(true) {
        int n;
        cin >> n;
        if(n==0) break;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int x; cin >> x; v.push_back(x);
        }
        vector<int> b(n, 0);
        for(int i = 0; i < 6; i++) {
            b[i] = 1;
        }
        while(true) {
            for(int j = 0; j < b.size(); j++) {
                if(b[j]) cout << v[j] << ' ';
            }cout << '\n';
            bool available = prev_permutation(b.begin(), b.end());
            if(!available) break;
        }cout << '\n';
    }
    return 0;
}