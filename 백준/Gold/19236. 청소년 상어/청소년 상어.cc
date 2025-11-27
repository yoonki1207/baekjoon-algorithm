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
ard와, 좌표를 직접 다루는 coor를 둘 다 선언한다.
 이유는 물고기의 번호(index)를 이용해 좌표를 얻어야하고, 또한 좌표(index)를 이용해 번호와 방향을 얻어야하기 때문이다. : 인덱싱 작업

*/
constexpr int BOARD_N = 4;
constexpr int SHARK = -1;
constexpr int offset_dir[9][2] = { {0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };
vector<vector<pii>> board;
vector<pii> entity_coords; // shark's coord is index 0

inline bool checkRange(const int x, const int y) {
    return x >= 0 && y >= 0 && x < BOARD_N && y < BOARD_N;
}

inline int nextDirection(const int dir) {
    return (dir % 8) + 1;
}

bool moveable(const vector<vector<pii>>& board, const vector<pii>& entity_coords, const int x, const int y, const int dir) {
    int nx = offset_dir[dir][0] + x;
    int ny = offset_dir[dir][1] + y;
    if (!checkRange(nx, ny)) return false;
    // if (board[nx][ny].first == SHARK) return false; // TODO: remove
    if (nx == entity_coords[0].first && ny == entity_coords[0].second) return false;
    return true;
}

void moveFish(vector<vector<pii>>& board, vector<pii>& entity_coords, const int fish_number) { // call only moveable
    const int x = entity_coords[fish_number].first;
    const int y = entity_coords[fish_number].second;
    const int dir = board[x][y].second;
    const int nx = x + offset_dir[dir][0];
    const int ny = y + offset_dir[dir][1];
    const int next_fish_number = board[nx][ny].first;
    swap(board[x][y], board[nx][ny]);
    entity_coords[fish_number] = { nx, ny };
    if (next_fish_number != 0) entity_coords[next_fish_number] = { x, y };
}

void removeFish(vector<vector<pii>>& board, vector<pii>& entity_coords, const int fish_number) {
    int x = entity_coords[fish_number].first;
    int y = entity_coords[fish_number].second;
    board[x][y] = { 0, 0 };
    entity_coords[fish_number] = { -1, -1 };
}

// bool fishExist(vector<vector<pii>>& board, vector<pii>& entity_coords, const int fish_number) {
//     return entity_coords[fish_number].first > 0;
// }

int dfs(vector<vector<pii>> board, vector<pii> entity_coords) {
    // eat fish
    int ret = 0;
    int shark_x = entity_coords[0].first;
    const int shark_y = entity_coords[0].second;
    const pii target_fish_info = board[shark_x][shark_y];
    const int dir = target_fish_info.second;
    ret += target_fish_info.first;
    removeFish(board, entity_coords, target_fish_info.first);
    
    // move fish
    for (int fish_number = 1; fish_number <= BOARD_N * BOARD_N; fish_number++) {
        if (entity_coords[fish_number].first == -1) continue;
        const pii fish_coord = entity_coords[fish_number];
        bool canmove = false;
        int x = fish_coord.first, y = fish_coord.second;
        int next_dir = board[x][y].second;
        for (int i = 0; i < 8; i++) {
            if (moveable(board, entity_coords, x, y, next_dir)) {
                canmove = true;
                break;
            }
            else {
                next_dir = nextDirection(next_dir);
            }
        }
        if (canmove) {
            board[x][y].second = next_dir;
            moveFish(board, entity_coords, fish_number);
        }
    }

    // move shark
    int nx = shark_x + offset_dir[dir][0];
    int ny = shark_y + offset_dir[dir][1];
    
    while (checkRange(nx, ny)) {
        if (board[nx][ny].first > 0) {
            int fish_number = board[nx][ny].first;
            // after shark moves
            entity_coords[0] = {nx, ny};
            // if can move, then dfs
            int max_cost = dfs(board, entity_coords);
            ret = max(ret, max_cost + target_fish_info.first);
        }
        nx += offset_dir[dir][0];
        ny += offset_dir[dir][1];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    board = vector<vector<pii>>(BOARD_N, vector<pii>(BOARD_N));
    entity_coords = vector<pii>(BOARD_N * BOARD_N + 1);
    for (int i = 0; i < BOARD_N; i++) {
        for (int j = 0; j < BOARD_N; j++) {
            int x, y;
            cin >> x >> y;
            board[i][j] = { x, y };
            entity_coords[x] = { i, j };
        }
    }
    int res = dfs(board, entity_coords);
    cout << res << endl;

    return 0;
}