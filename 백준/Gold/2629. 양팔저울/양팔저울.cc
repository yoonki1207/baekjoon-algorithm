#include <iostream>
#include <algorithm>

using namespace std;

/*
# conditions
추의 개수 N <= 30
M <= 7
추의 무게 <= 500
구슬의 무게 <= 40,000
*/
int N, M;
vector<int> vWeight, vBall;

/*
cache[idx][weight]
idx 까지 사용했을 때,
weight 차이가 나는 저울을 만들 수 있다
*/
vector<vector<int>> cache;

void Input() {
    cin >> N; // 추의 개수
    vWeight = vector<int>(N);
    for(int i = 0; i < N; i++) cin >> vWeight[i];
    cin >> M; // 구슬의 개수
    vBall = vector<int>(M);
    for(int i = 0; i < M; i++) cin >> vBall[i];
}

// idx: idx까지 추를 이용한 경우, weight: 현재 양팔저울의 무게의 차이
void dfs(int idx, int weight) {
    if(cache[idx][weight])
        return;
    cache[idx][weight] = true;
    if(idx == N) return;
    /*
    1. 양팔저울에서 무거운(혹은 같은) 쪽에 추 하나를 올리는 경우
    2. 그 반대에 추 하나를 올리는 경우
    3. 해당 추를 안 올리는 경우

    만약 idx까지 이용했을 때, 이미 재보았던 결과라면 더이상 확인할 필요가 없음
    */
   dfs(idx + 1, weight);
   dfs(idx + 1, weight + vWeight[idx]);
   dfs(idx + 1, abs(weight - vWeight[idx]));
}

bool isValid(int ball) {
    for(int i = 0; i < cache.size(); i++) {
        if(cache[i][ball]) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Input();
    cache = vector<vector<int>>(N + 1, vector<int>(500 * (N + 1), false));
    dfs(0, 0);
    for(int i = 0; i < M; i++) {
        if(isValid(vBall[i])) {
            cout << "Y ";
        } else {
            cout << "N ";
        }
    }
    return 0;
}