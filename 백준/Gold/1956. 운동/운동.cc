#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#define INF 987654321
#define MAX_N 101
#define lld long long
#define pii pair<int, int>

using namespace std;


/*
백준 1956
단방향 간선이 있는 그래프가 주어졌을 떄 가장 길이가 작은 사이클을 찾는 것.
V, E
2 <= V <= 400, 0 <= E <= V(V-1) = 159'600

사이클 탐지 최단거리 알고리즘 이용할 것.
벨만포드 있는데 기억 안남. 3중 반복문 이용할 것.

.. 16분 지나고 실수란걸 깨달음... 그냥 dfs하면될듯?
dfs = O(VE) : 인접리스트
O(VE)*V = 400 * 400^2 * 400 = 400^4
ever_visited를 이용한다면? 시간초과(TLE)가 안나지 않을까
35분째 TLE 남.

다시 처음으로 돌아와 와샬 프로이드가 맞았다.. 이 간단한걸..
*/
int V, E;
vector < vector<int>> arr;

void floyd() {
    for (int transit = 1; transit <= V; transit++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (arr[i][j] > arr[i][transit] + arr[transit][j]) {
                    arr[i][j] = arr[i][transit] + arr[transit][j];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    arr = vector<vector<int>>(V + 1, vector<int>(V+1, INF));
    for (int i = 1; i <= V; i++) arr[i][i] = 0;
    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        arr[a][b] = c;
    }
    floyd();
    int ans = INF;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i != j) {
                ans = min(ans, arr[i][j] + arr[j][i]);
            }
        }
    }
    if (ans == INF) ans = -1;
    cout << ans;


    return 0;
}