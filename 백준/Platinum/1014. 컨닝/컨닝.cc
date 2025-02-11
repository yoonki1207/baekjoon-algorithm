#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

void dfs(int row, int n, int d, int x, vector<int>& v, vector<int>& history) {
    if(d>=n) {
        if(history[x] == false) {
            v.push_back(x);
        }
        return;
    }
    if(row & (1<<(n-1-d))) {
        dfs(row, n, d+1, x, v, history);
        return;
    }
    dfs(row, n, d+1, x, v, history);
    x |= (1<<(n-1-d));
    dfs(row, n, d+2, x, v, history);
}

vector<int> getSits(int row, int n) { // 고장난 자리가 존재하는 행에 대해서 앉을 수 있는 경우의 수 리스트
    vector<int> ret;
    vector<int> history(2048);
    dfs(~row, n, 0, 0, ret, history);
    return ret;
}

vector<int> getFrontSits(int x, int frontRow, int n) {
    vector<int> v = getSits(frontRow, n);
    int possibleSit = 0;
    for(int i = 0; i < n; i++) {
        if(x & (1<<i)) {
            if(i+1<n)
                possibleSit |= (1<<(i+1));
            if(i>0)
                possibleSit |= (1<<(i-1));
        }
    }
    possibleSit = ~possibleSit;
    vector<int> ret;
    for(int i = 0; i < v.size(); i++) {
        if((possibleSit | v[i]) == possibleSit) {
            ret.push_back(v[i]);
        }
    }
    return ret;
}

int countSit(int x, int n) {
    int ret = 0;
    for(int i = 0; i < n; i++) {
        if(x & (1<<i)) {
            ret++;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        int arr[10] = {0};
        int dp[10][2048] = {0};
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            for(int j = 0; j < m; j++) {
                if(v[i][m-1-j] == '.') {
                    arr[i] |= (1<<j);
                }
            }
        }
        for(int row = 0; row < n; row++) {
            // 각 행에 대해서 앉을 수 있는 행을 만든다.
            vector<int> sits = getSits(arr[row], m);
            // 각 행의 앞 행이 앉을 수 있는 경우
            for(int i = 0; i < sits.size(); i++) {
                vector<int> frontSits = getFrontSits(sits[i], arr[row-1], m);
                const int nsit = countSit(sits[i], m);
                for(int j = 0; j < frontSits.size(); j++) {
                    if(row > 0) {
                        dp[row][sits[i]] = max(dp[row][sits[i]], dp[row-1][frontSits[j]]);
                    }
                }
                dp[row][sits[i]] += nsit;
            }
        }
        int ans = 0;
        for(int i = 0; i < 2048; i++) {
            ans = max(ans, dp[n-1][i]);
            }
        cout << ans << endl;

    }
    return 0;
}
/**

000
000

141
121

 */