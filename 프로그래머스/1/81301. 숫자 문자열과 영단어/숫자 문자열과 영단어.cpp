#include <string>
#include <vector>

using namespace std;

const string CODE[10] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++) {
        
        for(int j = 0; j < 10; j++) {
            if(i+CODE[j].size() - 1 < s.size() && s.substr(i, CODE[j].size()).compare(CODE[j]) == 0) {
                s = s.substr(0, i) + to_string(j) + s.substr(i+CODE[j].size(), -1);
                
                break;
            }
        }
    }
    return stoi(s);
}