#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int odd = 0;
	for(int i = 0; i < s.size(); i++) {
		while(s[i] != ' ' && i < s.size()) {
			if(odd%2 == 0) {
				answer+=(char)toupper(s[i]);
			} else {
				answer+=(char)tolower(s[i]);
			}
			odd++;
			i++;
		}
		if(i < s.size()) answer += ' ';
		odd = 0;
	}
    return answer;
}