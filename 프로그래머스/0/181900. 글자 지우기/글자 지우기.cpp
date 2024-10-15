#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    sort(indices.begin(), indices.end());
    int index = 0;
    for(int i = 0; i < my_string.size(); i++) {
        if(i == indices[index]) {
            index++;
            continue;
        }
        answer += my_string[i];
    }
    
    return answer;
}