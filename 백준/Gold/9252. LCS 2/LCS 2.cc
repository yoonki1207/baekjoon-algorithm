#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#include <string.h>
#include <time.h>
#define INF 987654321
#define lld long long int
#define pii pair<int, int>
// #define DEBUG
#define MOD 1000000009

using namespace std;

constexpr size_t MAX_N = 1001;
int arr[MAX_N][MAX_N];
string A, B;
int ans;
bool printed = false;

void dfs(int y, int x, int prev_val, vector<char> v) {
    if(v.size() == ans && !printed) {
        printed = true;
        for(int i = 0; i < v.size(); i++) {
            cout << v[i];
        } cout << endl;
    } 
    for(int i = y; i < A.size(); i++) {
        for(int j = x; j < B.size(); j++) {
            if(A[i] == B[j]) {
                v.push_back(A[i]);
                dfs(i + 1, j + 1, arr[i][j], v);
                v.pop_back();
                break;
            }
        }
    }
}

void findCorner(int& y, int& x) {
    int val = arr[y][x];
    for(int i = y; i >= 0 && arr[i][x] == val; i--) {
        for(int j = x; j >= 0 && arr[i][j] == val; j--) {
            if((j - 1 < 0 || arr[i][j - 1] != val) && (i - 1 < 0 || arr[i - 1][j] != val)) {
                y = i;
                x = j;
                return;
            }
        }
    }
}

void solve() {
    int y = A.size() - 1;
    int x = B.size() - 1;
    vector<char> v;
    while(y >= 0 && x >= 0) {
        if(arr[y][x] == 0) break;
        findCorner(y, x);
        v.push_back(A[y]);
        y--; x--;
    }
    while(!v.empty()) {
        cout << v.back(); v.pop_back();
    }
}


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B;
    int val = 0;
    for(int j = 0; j < B.size(); j++) {
        if(A[0] ==  B[j]) val = 1;
        arr[0][j] = val;
    }
    val = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == B[0]) val = 1;
        arr[i][0] = val;
    }
    for(int i = 1; i < A.size(); i++) {
        for(int j = 1; j < B.size(); j++) {
            if(A[i] == B[j]) {
                arr[i][j] = arr[i-1][j-1]+1;
            } else {
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    ans = arr[A.size()-1][B.size()-1];
    cout << ans << '\n';
    vector<char> v;
    // dfs(0, 0, 0, v);
    solve();
    

    return 0;
}