#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    set<string> s;
    string blinds = message;
    for(vector<int> ranges: spoiler_ranges) {
        for(int i = ranges[0]; i <= ranges[1]; i++) {
            if(blinds[i] != ' ') {
                blinds[i] = '*';
            }
        }
    }
    
    stringstream ss(blinds);
    string word;
    while(ss >> word) {
        s.insert(word);
    }
    
    ss.clear();
    ss.str(message);
    while(ss >> word) {
        if(!s.contains(word)) {
            answer++;
            s.insert(word);
        }
    }
    return answer;
}
