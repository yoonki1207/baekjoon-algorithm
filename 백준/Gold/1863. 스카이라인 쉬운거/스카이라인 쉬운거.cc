#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#include <set>
#define INF 987654321
#define lld long long
#define pii pair<int, int>

using namespace std;
/*
백준 1867
*/
constexpr int MAX_X = 1'000'001;
int N;
vector<int> v;
vector<pii> skylines;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    int x, y;
    skylines = vector<pii>(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        skylines[i] = { x, y };
    }
    skylines[N] = { MAX_X, 0 };
    sort(skylines.begin(), skylines.end());
    v.push_back(0);
    int cnt = 0;
    for (int i = 0; i <= N; i++) {
        int next = skylines[i].second;
        if (!v.empty() && v.back() < next) {
            v.push_back(next);
        }
        else if (!v.empty() && v.back() > next) {
            while (!v.empty() && v.back() >= next) { // back이 더 작을 때까지
                if(v.back() > next)
                    cnt++;
                v.pop_back();
            }
            v.push_back(next);
        }
        else {

        }
    }
    cout << cnt << endl;

    return 0;
}
