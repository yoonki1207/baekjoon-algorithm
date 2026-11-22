#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

/*
        Few     Fe
    -   CD  CD  Few
    0   1   2   3
*/
vector<vector<string>> v;
int U, N;

void Input() {
    v = vector<vector<string>>(10'001);
    cin >> U >> N;

    string name; int claim;
    for(int i = 0; i < N; i++) {
        cin >> name >> claim;
        v[claim].push_back(name);
    }
}

void Solve() {
    int less_dup = INF;
    for(int i = 0; i < v.size(); i++) {
        int curr_dup = v[i].size();
        if(curr_dup == 0) {
            continue;
        }
        if(curr_dup < less_dup) {
            less_dup = curr_dup;
        }
    }
    // less_dup 최소중복횟수
    for(int i = 0; i < v.size(); i++) {
        if(less_dup == v[i].size()) {
            cout << v[i][0] << ' ' << i;
            return;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    Input();
    Solve();

    return 0;
}