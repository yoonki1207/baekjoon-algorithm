#include <string>
#include <vector>

using namespace std;

int result[4][2] = {0};

pair<int, int> getIndex(char c) {
    int first = 0, second = 0;
    switch(c) {
        case 'T':
            second = 1;
        case 'R':
            first = 0;
            break;
        case 'F':
            second = 1;
        case 'C':
            first = 1;
            break;
        case 'M':
            second = 1;
        case 'J':
            first = 2;
            break;
        case 'N':
            second = 1;
        case 'A':
            first = 3;
            break;
        default:
            break;
    }
    return {first, second};
}

void addScore(string s, int choice) {
    choice = choice - 4;
    if(choice < 0) {
        pair<int, int> p = getIndex(s[0]);
        result[p.first][p.second] += -choice;
    } else {
        pair<int, int> p = getIndex(s[1]);
        result[p.first][p.second] += choice;
    }
}

char reverseChar(const char c) {
    if(c == 'R') return 'T';
    if(c == 'C') return 'F';
    if(c == 'J') return 'M';
    return 'N';
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "RCJA";
    for(int i = 0; i < survey.size(); i++) {
        addScore(survey[i], choices[i]);
    }
    for(int i = 0; i < 4; i++) {
        if(result[i][0] < result[i][1]) {
            answer[i] = reverseChar(answer[i]);
        }
    }
    return answer;
}
// RT, CF, JM, AN