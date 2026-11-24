#include <iostream>
#include <algorithm>
#include <map>

#define INF 987654321

using namespace std;

int T, n;
map<long long, int> mCnt;

void Input() {
    long long x;
    cin >> n;
    mCnt.clear();
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(mCnt.find(x) != mCnt.end()) {
            mCnt[x]++;
        } else {
            mCnt.insert({x, 0});
        }
    }
    return;
}

void Solve() {
    vector<pair<long long, int>> entries(mCnt.begin(), mCnt.end());
    stable_sort(entries.begin(), entries.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
    if(entries[0].second < n/2) {
        cout << "SYJKGW\n";
    } else {
        cout << entries[0].first << '\n';
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        Input();
        Solve();
    }
    
    return 0;
}