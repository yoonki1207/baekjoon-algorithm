#include <string>
#include <vector>

using namespace std;

int offset[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline bool isRange(int h, int w, int max_h, int max_w) {
    return h >= 0 && w >= 0 && h < max_h && w < max_w;
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    string s = board[h][w];
    for(int i = 0; i < 4; i++) {
        int nh = h + offset[i][0];
        int nw = w + offset[i][1];
        if(!isRange(nh, nw, board.size(), board[0].size())) {
            continue;
        }
        if(s.compare(board[nh][nw]) == 0) {
            answer++;
        }
    }
    return answer;
}