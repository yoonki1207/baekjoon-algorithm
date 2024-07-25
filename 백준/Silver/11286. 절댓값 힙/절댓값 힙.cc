#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <unordered_map>
#define MAX_N 10001
#define MAX_WEIGHT 1000000000

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    for(;n--;) {
        int x;
        cin >> x;
        if(x == 0) {
            if(pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        } else {
            pq.push({abs(x), x});
        }
    }
    return 0;
}