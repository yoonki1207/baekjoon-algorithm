#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

int len = 0;

int diffA(char a) {
    int d = (int)(a - 'A');
    int f = (int)('Z'-a) + 1;
    return min(abs(d), abs(f));
}

int solution(string name) {
    int answer = 0;
    string s = "";
    len = name.size();
    for(int i = 0; i < name.size(); i++) s += 'A';
    for(int i = 0; i < name.size(); i++) {
        answer += diffA(name[i]);
    }
    // DIHOAAASDOIH
    // SDAAAAAAAAAAAIO
    // SDAWEWEAAAAASD
    // AAAAAADDAAA
    // index 0 부터 탐색
    // A를 찾으면 왼쪽으로 A가 아닐 때까지 탐색
    // 오른 쪽으로 A가 아닐 때까지 탐색
    int moves = len-1;
    for(int i = 0; i < len; i++) {
        if(name[i] != 'A') continue;
        int li = i-1;
        int ri = i+1;
        if(li == -1) li = len - 1;
        if(ri == len) ri = 0;
        while(li != i) {
            if(name[li] != 'A') {
                break;
            }
            li--;
            if(li == -1) li = len - 1;
        }
        while(ri != i) {
            if(name[ri] != 'A') {
                break;
            }
            ri++;
            if(ri == len) ri = 0;
        }
        if(i == li && li == ri) {
            moves = 0;
            break;
        } else if(li < ri) {
            int a = li+1;
            int b = len-ri;
            moves = min(2*(a-1)+b, min(moves, 2*b-1+a));
        } else if(li >= ri) {
            int a = li;
            int b = len-ri;
            moves = min(a, min(moves, b));
        }
    }
    
    
    return answer+moves;
}