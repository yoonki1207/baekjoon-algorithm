#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

const int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int min_cost[25][25][4];
int n;

void dfs(int y, int x, vector<vector<bool>> visited, int prev_dir, int cost, const vector<vector<int>>& board) {
    int ret = cost;
    if(prev_dir != 5 && min_cost[y][x][prev_dir] <= cost) return;
    min_cost[y][x][prev_dir] = cost;
    for(int i = 0; i < 4; i++) {
        int ny = y + r[i][0];
        int nx = x + r[i][1];
        if(nx<0 || ny<0 || nx >= n || ny >= n || visited[ny][nx] || min_cost[ny][nx][prev_dir] <= ret || board[ny][nx] == 1) continue;
        int next_cost = 100;
        if(!(x == 0 && y == 0) && prev_dir / 2 != i / 2) { // 90degree
            next_cost += 500;
        }
        visited[ny][nx] = true;
        dfs(ny, nx, visited, i, ret + next_cost, board);
        visited[ny][nx] = false;
    }
}

int solution(vector<vector<int>> board) {
    for(int i = 0; i < board.size(); i++) for(int j = 0; j < board[0].size(); j++) 
        for(int k = 0; k < 4; k++)min_cost[i][j][k] = 987654321;
    n = board.size();
    int answer = 0;
    vector<vector<bool>> visited(25, vector<bool>(25));
    dfs(0, 0, visited, 5, 0, board);
    answer = min_cost[n-1][n-1][0];
    for(int i = 1; i < 4; i++) {
        answer = min(answer, min_cost[n-1][n-1][i]);
    }
    return answer;
}