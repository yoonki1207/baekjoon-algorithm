#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int ans[100];
int arr[100];
int n;

bool circ(int index, int* tmp, const int& startIndex, int c) {
    tmp[index] = 1;
    if(index == startIndex) return true;
    if(c >= n) return false;
    return circ(arr[index], tmp, startIndex, c+1);
}

void solve(int index) {
    if(ans[index] == 1) return;
    if(arr[index] == index) {
        ans[index] = 1;
    } else {
        int tmp[100] = {0};
        int c = 0;
        bool isCirc = circ(arr[index], tmp, index, c);
        if(isCirc) {
            for(int i = 0; i < n; i++) {
                if(tmp[i]) ans[i] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int k = 0;
        cin >> k;
        arr[i] = k-1;
    }
    for(int i = 0; i < n; i++) {
        solve(i);
    }
    int answer = 0;
    for(int i = 0; i < n; i++) {
        answer += ans[i];
    }
    cout << answer << endl;
    for(int i = 0; i < n; i++) {
        if(ans[i]) {
            cout << i+1 << endl;
        }
    }
    return 0;
}