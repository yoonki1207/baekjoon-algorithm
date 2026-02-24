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
#define pdd pair<double, double>
// #define DEBUG
// #define MOD 1000000009

using namespace std;

/*
백준 7682
X가 선이다.
X의 개수와 O의 개수를 각각 a, b이라고 하면, a == b이거나 a == b+1이어야만한다.
최종상태에서
X가 이기거나, O가 이기거나, 바둑판이 가득 차있거나.
3연속으로 이루어진 X줄이 유일하거나 O줄이 유일하어야만한다.
*/

pair<int, int> cntLine(const string& board) {
    int a = 0, b = 0;
    for(int i = 0; i < 3; i++) {
        bool ha = true, va = true, hb = true, vb = true;
        for(int j = 0; j < 3; j++) {
            if(board[i*3+j] != 'X') ha = false; // 가로
            if(board[i*3+j] != 'O') hb = false;
            if(board[i+j*3] != 'X') va = false; // 세로
            if(board[i+j*3] != 'O') vb = false;
        }
        if(ha) ++a;
        if(va) ++a;
        if(hb) ++b;
        if(vb) ++b;
    }
    bool ca = true, cb = true, ra = true, rb = true;
    for(int i = 0; i < 3; i++) {
        if(board[i*3+i] != 'X') ca = false;
        if(board[i*3+2-i] != 'X') ra = false;
        if(board[i*3+i] != 'O') cb = false;
        if(board[i*3+2-i] != 'O') rb = false;
    }
    if(ca) ++a;
    if(ra) ++a;
    if(cb) ++b;
    if(rb) ++b;
    return {a, b};
}

string str;
bool ans = false;
set<string> sets;
void bfs() {
    queue<pair<string, int>> q;
    q.push({".........", 0});
    while(!q.empty()) {
        string s = q.front().first;
        int n = q.front().second;
        q.pop();
        pair<int, int> res = cntLine(s);
        if(res.first || res.second || n == 9) {
            sets.insert(s);
            continue;
        }

        for(int i = 0; i < 9; i++) {
            if(s[i] != '.') continue;
            string tmp = s;
            if(n % 2 == 0) {
                tmp[i] = 'X';
                q.push({tmp, n + 1});
            } else {
                tmp[i] = 'O';
                q.push({tmp, n + 1});
            }

        }
    }
}
int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    bfs();
    while(true) {
        cin >> str;
        if(str.compare("end") == 0) break;
        // bruteForce();
        if(sets.find(str) != sets.end()) ans = true;
        else ans = false;
        if(ans) {
            cout << "valid\n";
        } else {
            cout << "invalid\n";
        }
    }
    return 0;
}
