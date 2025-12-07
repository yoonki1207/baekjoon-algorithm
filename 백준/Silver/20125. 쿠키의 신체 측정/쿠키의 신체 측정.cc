#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#define INF 987654321
#define lld long long
#define pii pair<int, int>

using namespace std;


/*
백준 129886 돌 그룹
DP 문제인듯

500 * 500 * 500 = 
*/

constexpr int MAX_N = 1001;
int N;
char arr[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    string s;
    pii heart = { -1, -1 };
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            arr[i][j] = s[j];
            if (heart.first == -1 && s[j] == '*') {
                heart = { i+1, j };
            }
        }
    }
    int left_arm = 0, right_arm = 0, body = 0, left_leg = 0, right_leg = 0;
    for (int i = 0; i < heart.second; i++) {
        if (arr[heart.first][i] == '*') {
            left_arm++;
        }
    }
    for (int i = heart.second+1; i < N; i++) {
        if (arr[heart.first][i] == '*') {
            right_arm++;
        }
    }
    for (int i = heart.first + 1; i < N; i++) {
        if (arr[i][heart.second] == '*') {
            body++;
        }
    }
    for (int i = heart.first + body + 1; i < N; i++) {
        if (arr[i][heart.second - 1] == '*') {
            left_leg++;
        }
        if (arr[i][heart.second + 1] == '*') {
            right_leg++;
        }
    }
    cout << heart.first + 1 << ' ' << heart.second + 1 << endl;
    cout << left_arm << ' ' << right_arm << ' ' << body << ' ' << left_leg << ' ' << right_leg;
    return 0;
}