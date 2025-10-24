#include <string>
#include <vector>
#include <queue>
#define MAX 53

using namespace std;

const int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char arr[MAX][MAX];

void clearEdge(const char request) {
    bool visited[MAX][MAX] = {0};
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    vector<pair<int, int>> ds;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + r[i][0];
            int nx = x + r[i][1];
            if(ny >= 0 && nx >= 0 && ny < MAX && nx < MAX) {
                if(visited[ny][nx]) continue;
                visited[ny][nx] = true;
                if(arr[ny][nx] == request) {
                    ds.push_back({ny, nx});
                } else if(arr[ny][nx] == 0) {
                    q.push({ny, nx});
                }
            }
        }
    }
    for(int i = 0; i < ds.size(); i++) {
        arr[ds[i].first][ds[i].second] = 0;
    }
}

void clearAll(const char request) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(arr[i][j] == request) {
                arr[i][j] = 0;
            }
        }
    }
}

int cntAll() {
    int ret = 0;
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(arr[i][j] != 0) ret++;
        }
    }
    return ret;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    for(int i = 0; i < storage.size(); i++) {
        for(int j = 0; j < storage[i].size(); j++) {
            arr[i+1][j+1] = storage[i][j];
        }
    }
    for(int i = 0; i < requests.size(); i++) {
        const string& request = requests[i];
        if(request.size() > 1) {
            clearAll(request[0]);
        } else {
            clearEdge(request[0]);
        }
    }
    answer = cntAll();
    return answer;
}