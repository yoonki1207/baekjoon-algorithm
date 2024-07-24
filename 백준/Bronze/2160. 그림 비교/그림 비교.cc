#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int arr[50][5][7];


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        for(int j = 0; j < 5; j++) {
            cin >> s;
            for(int k = 0; k < 7; k++) {
                arr[i][j][k] = s[k] == '.' ? 0 : 1;
            }
        }
    }
    int ans = 50;
    pair<int, int> p;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int diffN = 0;
            for(int k = 0; k < 5; k++) {
                for(int l = 0; l < 7; l++) {
                    if(arr[i][k][l] != arr[j][k][l]) {
                        ++diffN;
                    }
                }
            }
            if(ans > diffN) {
                ans = diffN;
                p = {i + 1, j + 1};
            }
        }
    }
    cout << p.first << ' ' << p.second << endl;
    return 0;
}