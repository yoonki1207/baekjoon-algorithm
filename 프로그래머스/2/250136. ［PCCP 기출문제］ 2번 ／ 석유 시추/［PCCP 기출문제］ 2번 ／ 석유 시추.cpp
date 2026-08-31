#include <string>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int EMPTY = 0;
constexpr int OIL = 1;
constexpr int OFFSET_N = 4;
const int offset_y[4] = {0, 0, -1, 1};
const int offset_x[4] = {-1, 1, 0, 0};

vector<vector<int>> oil_metrix; // key: y, x / values: area number
vector<int> oil_volume; // key: area number / value: oil volume

// returns oil volume
int dfs(const int curr_area_number, int y, int x, 
        const vector<vector<int>>& land, 
        vector<vector<bool>>& visited, const int n, const int m) {
    
    if(land[y][x] == EMPTY) {
        return 0;
    }
    
    visited[y][x] = true;
    oil_metrix[y][x] = curr_area_number;
    int cnt = 1;
    for(int i = 0; i < OFFSET_N; i++) {
        int ny = y + offset_y[i];
        int nx = x + offset_x[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
        cnt += dfs(curr_area_number, ny, nx, land, visited, n, m);
    }
    return cnt;
}

void init_oil_metrix(const vector<vector<int>>& land, const int n, const int m) {
    oil_metrix = vector<vector<int>>(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int curr_n = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(land[i][j] == OIL && oil_metrix[i][j] == 0) {
                oil_volume[curr_n] = dfs(curr_n, i, j, land, visited, n, m);
                curr_n++;
            }
        }
    }
}

int drilling(const int x, const int n, const int m) {
    int total = 0;
    vector<bool> visited_area(n*m+1, false);
    for(int i = 0; i < n; i++) {
        int curr_area = oil_metrix[i][x];
        if(curr_area && !visited_area[curr_area]) {
            total += oil_volume[curr_area];
            visited_area[curr_area] = true;
        }
    }
    return total;
}

int retrieve_drilling(const int n, const int m) {
    int ret = 0;
    for(int i = 0; i < m; i++) {
        ret = max(ret, drilling(i, n, m));
    }
    return ret;
}

int solution(vector<vector<int>> land) {
    int n = land.size(), m = land[0].size();
    oil_volume = vector<int>(n*m + 1);
    init_oil_metrix(land, n, m);
    return retrieve_drilling(n, m);
    // return answer;
}