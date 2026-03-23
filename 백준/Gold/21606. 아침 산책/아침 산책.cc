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
#include <random>
#define INF 987654321
#define lld long long int
#define pii pair<int, int>
#define pdd pair<double, double>
// #define DEBUG
// #define MOD 1000000009

using namespace std;
int N;
string s;
vector<vector<int>> adj;
vector<bool> isIndoor;
vector<int> path;
vector<bool> visited;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int u, v;
    cin >> N;
    cin >> s;
    adj = vector<vector<int>>(N + 1);
    isIndoor = vector<bool>(N + 1, false);
    path = vector<int>(N + 1, 0); // attr
    visited = vector<bool>(N + 1, false);
    for(int i = 1; i <= N; i++) {
        isIndoor[i] = s[i-1] == '1';
    }
    for(int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int node = 1; node <= N; node++) {
        if(!isIndoor[node]) {
            // bfs
            int indoorCnt = 0;
            queue<int> q;
            vector<int> lst;
            q.push(node);
            lst.push_back(node);
            visited[node] = true;
            while(!q.empty()) {
                int front = q.front();
                q.pop();
                for(vector<int>::iterator iter = adj[front].begin(); iter != adj[front].end(); iter++) {
                    if(isIndoor[*iter]) {
                        indoorCnt++;
                    } else if(!visited[*iter]) {
                        visited[*iter] = true;
                        lst.push_back(*iter);
                        q.push(*iter);
                    }
                }
            }
            for(int i = 0; i < lst.size(); i++) {
                path[lst[i]] = indoorCnt;
            }
        }
    }
    int cnt = 0;
    for(int node = 1; node <= N; node++) {
        if(isIndoor[node]) {
            for(vector<int>::iterator iter = adj[node].begin(); iter != adj[node].end(); iter++) {
                if(isIndoor[*iter]) {
                    cnt++;
                } else {
                    cnt += path[*iter] - 1;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}