#include <string>
#include <vector>

using namespace std;

int na[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int nb[4][2] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

bool checkRange(int y, int x) {
    return x>=0&&y>=0&&x<5&&y<5;
}

bool solve(vector<string> place) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(place[i][j] == 'P') {
                for(int k = 0; k < 4; k++) {
                    int ny = i+na[k][0];
                    int nx = j+na[k][1];
                    if(checkRange(ny, nx)) {
                        if(place[ny][nx] == 'P')
                            return false;
                        int nny = i+na[k][0]*2;
                        int nnx = j+na[k][1]*2;
                        if(checkRange(nny, nnx) && place[nny][nnx] == 'P'
                          &&place[ny][nx] != 'X') {
                            return false;
                        }
                    }
                    ny = i+nb[k][0];
                    nx = j+nb[k][1];
                    if(checkRange(ny, nx) && place[ny][nx] == 'P'
                      && ( place[i+na[k][0]][j+na[k][1]] == 'O'
                        || place[i+na[(k+1)%4][0]][j+na[(k+1)%4][1]] == 'O'
                         )
                      ) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0; i < places.size(); i++) {
        answer.push_back(
            solve(places[i]) ? 1 : 0
        );
    }
    return answer;
}