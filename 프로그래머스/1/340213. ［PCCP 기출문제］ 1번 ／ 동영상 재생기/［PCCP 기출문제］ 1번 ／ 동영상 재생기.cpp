#include <string>
#include <vector>

using namespace std;

int prev(int curr) {
    if(curr - 10 < 0) return 0;
    else return curr - 10;
}

int next(int curr, int len) {
    if(curr + 10 > len) return len;
    else return curr + 10;
}

int skipOp(int curr, int op_start, int op_end) {
    if(curr >= op_start && curr < op_end) return op_end;
    else return curr;
}

int toInt(string t) {
    int ret = (
        ((int)(t[0]-'0'))*10 + ((int)(t[1]-'0'))
    )*60 + 
        ((int)(t[3]-'0'))*10 + 
        (int)(t[4]-'0');
    return ret;
}

string toResult(int t) {
    char trr[5] = {0, 0, ':', 0, 0};
    trr[4] = t % 10 + '0';
    trr[3] = t % 60 / 10 + '0';
    trr[1] = t / 60 % 10 + '0';
    trr[0] = t / 60 / 10 + '0';
    string ret(trr);
    return ret;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int curr = toInt(pos);
    int opStart = toInt(op_start);
    int opEnd = toInt(op_end);
    int videoLen = toInt(video_len);
    curr = skipOp(curr, opStart, opEnd);
    for(vector<string>::iterator iter = commands.begin();
       iter != commands.end();
       iter++) {
        if(iter->compare("prev") == 0) {
            curr = prev(curr);
        } else {
            curr = next(curr, videoLen);
        }
        curr = skipOp(curr, opStart, opEnd);
    }
    return toResult(curr);
}