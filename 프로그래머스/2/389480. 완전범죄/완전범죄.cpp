#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 987654321

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = INF;
    int dp[42][122] = {0};
    for(int i = 0; i < 41; i++) {
        for(int j = 0; j < 121; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= info.size(); i++) {
        int a = info[i-1][0];
        int b = info[i-1][1];
        for(int j = 0; j < m; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j] + a);
            
            if(j + b < m) {
                dp[i][j+b] = min(dp[i][j+b], dp[i-1][j]);
            }
        }
    }
    
    for(int i = 0; i < m; i++) {
        answer = min(answer, dp[info.size()][i]);
    }
    
    return answer >= n ? -1 : answer;
}

/*
과거에서 미래를 알긴 어려우니까
현재에서 과거를 알아본다.
즉, dp를 사용.
case 1, index 1 에서 [2,3]일 때, 어떤 상황인지 알아보자.
만약 A가 훔친다면 A의 누적 흔적은 2+a이다. 과거 [a, b]에 대해서 업데이트를 하면 된다.
120*120*40
576000

B A B
[1, 2]
[1, 0] = 1, [0, 2] = 0
[2, 3]
[3, 0] = 3, [2, 2] = 2, [1, 3] = 1, [0, 5] = 0
[2, 1]
[5, 0] = 5, [4, 2] = 4, [3, 3] = 3, [2, 5] = 2
[3, 1] = 3, [2, 3] = 2, [1, 4] = 1, [0, 6] = 0

[
[1, 2], 
[2, 3],
[2, 1], 
[1, 2], 
[2, 3], 
[2, 1], 
[1, 2],
[2, 3], 
[2, 1]]
15 18
0 18


*/