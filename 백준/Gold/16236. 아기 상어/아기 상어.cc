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

const int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N;
int arr[21][21];

inline bool checkRange(const int y, const int x) {return x>=0 && y>=0 && x < N && y < N;}

// inline int getDistnace(const pair<int, int>& a, const pair<int, int>& b) {
//     return abs(a.first - b.first) + abs(a.second - b.second);
// }

pair<int, pair<int, int>> eatableList(pair<int, int> shark, const int shark_size) {
    int distance = INF;
    vector<pair<int, int>> ret;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> visited(N, vector<bool>(N));
    pq.push({0, shark});
    while(!pq.empty()) {
        int d = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + r[i][0];
            int nx = x + r[i][1];
            if(!checkRange(ny, nx) || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            if(arr[ny][nx] > shark_size || distance < d+1) {
                continue;
            } else if (arr[ny][nx] == 0 || arr[ny][nx] == shark_size) {
                pq.push({d+1, {ny, nx}});
            } else {
                distance = d+1;
                pq.push({d+1, {ny, nx}});
                if(distance == d+1) {
                    ret.push_back({ny, nx});
                }
            }
        }
    }
    sort(ret.begin(), ret.end());
    // cout << "ret size: " << ret.size() << endl;
    if(ret.size() > 0) {
        return {distance, ret[0]};
    } else {
        return {-1, {-1, -1}};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    pair<int, int> shark;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 9) {
                shark = {i, j};
                arr[i][j] = 0;
            }
        }
    }
    int shark_size = 2, shark_exp = 0, t = 0;
    while(true) {
        pair<int, pair<int, int>> fish = eatableList(shark, shark_size);
        if(fish.first == -1) {
            break;
        }

        ++shark_exp;
        if(shark_exp == shark_size) {
            shark_size++;
            shark_exp = 0;
        }
        arr[fish.second.first][fish.second.second] = 0;
        t += fish.first;
        shark = fish.second;
    }
    cout << t;
    return 0;
}


/*
3
1 0 1
0 9 0
1 0 1

*/