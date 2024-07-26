#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <unordered_map>
#define MAX_N 10001
#define INF 987654321

using namespace std;
// prob 1445
int n, m;
char arr[50][50];
pair<int, int> cache[50][50]; // direct, nearby
int offset[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[50][50];
pair<int, int> ans = {INF, INF};

// it returns true when a is more efficiency then b

struct Point {
    int y;
    int x;
    int first;
    int second;
};

struct Eff {
    bool operator()(const Point& a, const Point& b) {
        if(a.first == b.first) 
            if(a.second < b.second) return false;
            else return true;
        return a.first >= b.first;
    }
};


priority_queue<Point, vector<Point>, Eff> pq;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    pair<int, int> start;
    pair<int, int> state;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++) {
            arr[i][j] = s[j];
            if(arr[i][j] == 'S') start = {i, j};
            cache[i][j] = {-1, -1};
        }
    }
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 'g') {
                for(int k = 0; k < 4; k++) {
                    int y = i + offset[k][0];
                    int x = j + offset[k][1];
                    if(y<0 || y>=n || x <0 || x>=m || arr[y][x] != '.') continue;
                    arr[y][x] = 'G';
                }
            }
        }
    }
    pq.push({start.first, start.second, 0, 0});
    while(!pq.empty()) {
        Point top = pq.top();
        pq.pop();
        for(int i = 0; i < 4; i++) {
            int y = top.y + offset[i][0];
            int x = top.x + offset[i][1];
            if(x < 0 || x >= m || y < 0 || y >= n || visited[y][x]) continue;
            if(arr[y][x] == 'F') {
                cout << top.first << ' ' << top.second << endl;
                return 0;
            }
            visited[y][x] = true;
            pq.push({y, x, top.first + (arr[y][x] == 'g'), top.second + (arr[y][x] == 'G')});
        }
    }
    

    
    cout << ans.first << ' ' << ans.second;
    return 0;
}

/*

6 6
......
g..F..
......
..g...
......
...S.g

6 6
......
g..F..
......
..gg..
......
...S.g

*/