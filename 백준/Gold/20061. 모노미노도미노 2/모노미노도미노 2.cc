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
#define MAX_N 32001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG
#define MOD 1000000009

using namespace std;

// 1: .  2: -  3: |

int BLOCKS[4][2][2] = {
    {
        {0, 0},
        {0, 0},
    },
    {
        {1, 0},
        {0, 0},
    },{
        {1, 1},
        {0, 0},
    },{
        {1, 0},
        {1, 0},
    },
};
int N;
int green_arr[6][4];
int blue_arr[6][4];
int score;

// arr: 판의 종류, t: 블럭의 타입, xy: 판에서의 블럭 위치
bool isCollision(const int (*arr)[4], const int t, const int x, const int y) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(BLOCKS[t][i][j] == 1) {
                if(x+i+1>=6) return true; // 밑에 닿음
                if(y+j>=4) continue; // 벽 벗어남
                if(arr[x+i+1][y+j] == 1) return true; // 밑에 블럭
            }
        }
    }
    return false;
}

void drop(const int _t, const int _x, const int _y) {
    int x = 0, y = _y, t = _t;
    while(!isCollision(green_arr, t, x, y)) {
        x++;
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            int nx = i + x;
            int ny = j + y;
            if(nx >= 6 || ny >= 4) continue;
            if(BLOCKS[t][i][j] == 1) {
                green_arr[nx][ny] = 1;
            }
        }
    }

    x = 0;
    y = 3-_x;
    t = (t == 1) ? 1 : (t == 2) ? 3 : 2; // 2 to 3, 3 to 2
    if(t == 2) {
        y--;
    }
    while(!isCollision(blue_arr, t, x, y)) {
        x++;
    }
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            int nx = i + x;
            int ny = j + y;
            if(nx >= 6 || ny >= 4) continue;
            if(BLOCKS[t][i][j] == 1) {
                blue_arr[nx][ny] = 1;
            }
        }
    }
}

// erase line and fill as drop
int eraseLine(int (*arr)[4]) {
    int ret = 0;
    for(int i = 2; i < 6; i++) {
        bool isClearable = true;
        for(int j = 0; j < 4; j++) {
            if(arr[i][j] == 0) isClearable = false;
        }
        if(isClearable) {
            for(int r = i; r > 0; r--) {
                for(int c = 0; c < 4; c++) {
                    arr[r][c] = arr[r-1][c];
                }
            }
            for(int c = 0; c < 4; c++) {
                arr[0][c] = 0;
            }
            ret++;
        }
    }
    return ret;
}

bool lightColored(int (*arr)[4]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++) {
            if(arr[i][j] == 1) return true;
        }
    }
    return false;
}

void moveDown(int (*arr)[4]) {
    for(int i = 5; i > 0; i--) {
        for(int j = 0; j < 4; j++) {
            arr[i][j] = arr[i-1][j];
        }
    }
    for(int j = 0; j < 4; j++) {
        arr[0][j] = 0;
    }
}

void solve(const int t, const int x, const int y) {
    drop(t, x, y);
    score += eraseLine(green_arr);
    score += eraseLine(blue_arr);
    while(lightColored(green_arr)) moveDown(green_arr);
    while(lightColored(blue_arr)) moveDown(blue_arr);
}

int count_board_block(int (*arr)[4]) {
    int ret = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 4; j++) {
            if(arr[i][j] == 1) ret++;
        }
    }
    return ret;
}

void display() {
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 4; j++) {
            cout << green_arr[i][j] << ' ';
        }
        cout << ' ';
        for(int j = 0; j < 4; j++) {
            cout << blue_arr[i][j] << ' ';   
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    int t, x, y;
    for(int i = 0; i < N; i++) {
        cin >> t >> x >> y;
        solve(t, x, y);
        // display();
    }

    int count_all = count_board_block(green_arr) + count_board_block(blue_arr);
    cout << score << '\n' << count_all;
    
    return 0;
}

/*
2
1 1 1
2 3 0
*/