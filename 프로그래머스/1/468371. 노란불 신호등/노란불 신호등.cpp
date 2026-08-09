#include <string>
#include <vector>

#define GREEN 0
#define YELLOW 1
#define RED 2
#define COLOR int

using namespace std;

COLOR get_signal(const vector<int> signal, int t, const int s) {
    t = t % s;
    if(t < signal[0]) return GREEN;
    if(t < signal[0] + signal[1]) return YELLOW;
    return RED;
}

int solution(vector<vector<int>> signals) {
    int answer = 0;
    int n = signals.size();
    vector<int> sizes(signals.size());
    for(int i = 0; i < n; i++) {
        sizes[i] = signals[i][0] + signals[i][1] + signals[i][2];
    }
    for(int i = 0; i < 3200000; i++) {
        bool ret = true;
        for(int j = 0; j < n; j++) {
            COLOR color = get_signal(signals[j], i, sizes[j]);
            if(color != YELLOW) ret = false;
        }
        if(ret) return i + 1;
    }
    return -1;
}


/*
2 + 1 + 2 = 5
5 + 1 + 1 = 7
최소공배수?

G Y R 을 R G Y로 바꾼다.

4 + 1 = 5
6 + 1 = 7

or
20 이하의 5개의 자연수의 최소공배수의 최대값이 1억 이하라면 해결 가능하다.
19 * 18 * 17 * 13 * 11 = 831402
20^5 = 3200000
*/