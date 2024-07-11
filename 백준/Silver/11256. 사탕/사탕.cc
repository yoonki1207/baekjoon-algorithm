#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T;
    cin >> T;
    while(T-->0) {
        int k, n;
        cin >> k >> n;
        vector<int> boxes;
        for(int i = 0; i < n; i++) {
            int r,c;
            cin >> r >> c;
            boxes.push_back(r*c);
        }
        sort(boxes.begin(), boxes.end(), greater<int>());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            k -= boxes[i];
            ans++;
            if(k <= 0) break;
        }
        cout << ans << endl;
    }

    return 0;
}