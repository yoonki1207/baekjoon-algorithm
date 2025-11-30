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

/*
백준 16954
벽이 1초에 한 칸씩 내려온다. 바닥 밑으로 가려는 벽은 사라진다.
-> 캐릭터가 1초에 한 칸씩 위로 올라가는 것으로 풀이. > 단순 BFS
*/

constexpr int BOARD_MAX = 8;
constexpr int OFFSET_MAX = 10;
constexpr int offset_y[OFFSET_MAX] = {-1, 0, 0, 0, -1, -1, 1, 1, 1, -1}; // up, stop, left, right, lu, ru, ld, rd, d, up
constexpr int offset_x[OFFSET_MAX] = {0, 0, -1, 1, -1, 1, -1, 1, 0, 0};
vector<vector<int>> board;

class Coord {
public:
    int x;
    int y;
    Coord() {}
    Coord(int x, int y): x(x), y(y) {}
    Coord getOffsetCoord(int offset_number) {
        Coord ret{x + offset_x[offset_number], y + offset_y[offset_number]};
        return ret;
    }
    bool checkRange(int board_h, int board_w) {
        return x >= 0 && y >= 0 && x < board_w && y < board_h;
    }
};


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    board = vector<vector<int>>(BOARD_MAX * 2, vector<int>(BOARD_MAX));

    for(int i = BOARD_MAX; i < BOARD_MAX * 2; i++) {
        cin >> s;
        for(int j = 0; j < BOARD_MAX; j++) {
            board[i][j] = s[j] == '.' ? 0 : 1;
        }
    }
    
    Coord player{0, BOARD_MAX * 2 - 1};
    queue<pair<Coord, int>> q;
    vector<vector<bool>> visited(BOARD_MAX*2, vector<bool>(BOARD_MAX, false));
    // visited[player.y][player.x] = true;
    q.push({player, 0});
    bool isReachable = false;
    while(!q.empty() && !isReachable) {
        Coord coord = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(coord.y < 8) { // y < 8부터는 방해할 수 있는 블럭이 없기에 탈출할 수있음.
            isReachable = true;
        }
        for(int i = 1; i < OFFSET_MAX; i++) {
            Coord offsetCoord = coord.getOffsetCoord(i);
            if(offsetCoord.checkRange(BOARD_MAX*2, BOARD_MAX) && 
            !visited[offsetCoord.y][offsetCoord.x] &&
            board[offsetCoord.y][offsetCoord.x] == 0) {
                visited[offsetCoord.y][offsetCoord.x] = true;
                Coord next = offsetCoord.getOffsetCoord(0); // move up
                if(board[next.y][next.x] == 0) { // push when it's empty block
                    q.push({next, depth + 1});
                }
            }
        }
    }
    cout << (isReachable ? 1 : 0);
    
    
    return 0;
}