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
#define MOD 1000000009

using namespace std;

struct Shark {
    int r;
    int c;
    int s;
    int d;
    int z;
};

int R, C, M;

void moveShark(Shark& shark) { // max(R, C) * 2
    int move_cnt = shark.s;
    if(shark.d <= 2) {
        move_cnt = move_cnt % (R*2 - 2);
        // if(move_cnt % 2 == 1) shark.d = shark.d == 1 ? 0 : 1;
    } else {
        move_cnt = move_cnt % (C*2 - 2);
        // if(move_cnt % 2 == 1) shark.d = shark.d == 3 ? 2 : 3;
    }
    while(move_cnt--) {
        if(shark.d == 1) {
            shark.r--;
            if(shark.r <= 0) {
                shark.d = 2;
                shark.r += 2;
            }
        } else if (shark.d == 2) {
            shark.r++;
            if(shark.r > R) {
                shark.d = 1;
                shark.r -= 2;
            }
        } else if (shark.d == 3) {
            shark.c++;
            if(shark.c > C) {
                shark.d = 4;
                shark.c -= 2;
            }
        } else {
            shark.c--;
            if(shark.c <= 0) {
                shark.d = 3;
                shark.c += 2;
            }
        }
    }
}

bool customSort(const Shark& a, const Shark& b) {
    if(a.r == b.r) {
        if(a.c == b.c) {
            return a.z > b.z;
        }
        return a.c < b.c;
    }
    return a.r < b.r;
}

vector<Shark> moveSharks(vector<Shark>& sharks) {
    vector<vector<vector<Shark>>> arr(R+1, vector<vector<Shark>>(C+1));
    for(vector<Shark>::iterator iter = sharks.begin(); iter != sharks.end(); iter++) { // M
        moveShark(*iter);
        arr[iter->r][iter->c].push_back(*iter);
    }
    vector<Shark> ret;
    for(int i = 1; i <= R; i++) { // 10,000
        for(int j = 1; j <= C; j++) {
            if(arr[i][j].size() > 1) {
                Shark winner = arr[i][j][0];
                for(int k = 1; k < arr[i][j].size(); k++) {
                    if(winner.z < arr[i][j][k].z) {
                        winner = arr[i][j][k];
                    }
                }
                ret.push_back(winner);
            } else if(arr[i][j].size() > 0) {
                ret.push_back(arr[i][j][0]);
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> R >> C >> M;
    vector<Shark> arr;
    int r, c, s, d, z;
    for(int i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        arr.push_back({r, c, s, d, z});
    }
    int pos = 0;
    int ans = 0;
    while(++pos <= C) {
        vector<Shark>::iterator catched = arr.end();
        // cout << "Sharks size is " << arr.size() << endl;
        for(int i = 0; i < arr.size(); i++) { // M
            // cout << "watched " << arr[i].r << ' ' <<arr[i].c << ' ' << arr[i].z << endl;
            if(arr[i].c == pos) {
                if(catched == arr.end()) {
                    catched = arr.begin()+i;
                } else if(arr[i].r < catched->r) {
                    catched = arr.begin()+i;
                }
            }
        }
        if(catched != arr.end()) {
            // cout << "Catched at: " << (catched->c) << ", size is " << catched->z << endl;
            ans += catched->z;
            arr.erase(catched); // M
        }
        arr = moveSharks(arr);
    }
    cout << ans << endl;
    return 0;
}

