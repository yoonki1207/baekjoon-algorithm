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
#define INF 987654321
#define MAX_N 32001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

const string CODE[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
int N, M;
vector<int> guitar;
vector<int> press;
int ans = INF;

int codetoi(string code) {
    for(int i = 0; i < 12; i++) if(code.compare(CODE[i]) == 0) return i;
    return -1;
}

void solve(int index, vector<int>& v) {
    if(index == N) {
        // TODO: update ans
        for(int i = 0; i < press.size(); i++) {
            bool pressed = false;
            for(int j = 0; j < v.size(); j++) {
                int plat = (guitar[j] + v[j]) % 12;
                if(plat == press[i]) {
                    pressed = true;
                }
            }
            if(!pressed) return;
        }
        int min_val = INF, max_val = v[0];
        for(int i = 0; i < v.size(); i++) {
            if(min_val > v[i] && v[i] != 0) min_val = v[i];
            if(max_val < v[i]) max_val = v[i];
            // cout << v[i] << ' ';
        }
        if(min_val == INF)
        ans = 0;
        else 
        ans = min(ans, max_val - min_val + 1);
        // cout << ": " << ans << ' ' << max_val << ' ' << min_val << endl;
        return;
    }
    int curr_code = guitar[index];
    for(int i = 0; i <= 24; i++) {
        curr_code = (guitar[index] + i) % 12;
        for(int j = 0; j < press.size(); j++) {
            if(curr_code == press[j]) {
                v.push_back(i);
                solve(index + 1, v);
                v.pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    guitar = vector<int>(N);
    press = vector<int>(M);
    string s;
    for(int i = 0; i < N; i++) {
        cin >> s;
        guitar[i] = codetoi(s);
    }
    for(int i = 0; i < M; i++) {
        cin >> s;
        press[i] = codetoi(s);
    }
    vector<int> stk;
    solve(0, stk);
    cout << ans << endl;
    return 0;
}

/*
1 2  3 4 5  6 7  8 9 0  1 2
"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"

E
A
D
G
B
E


*/