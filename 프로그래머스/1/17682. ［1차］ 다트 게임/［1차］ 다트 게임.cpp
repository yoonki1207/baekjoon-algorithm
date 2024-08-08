#include <string>
#include <math.h>
#include <vector>

using namespace std;

typedef struct Result {
    int score;
    char bonus;
    char option;
} Result;


vector<Result> getResults(string s) {
    vector<Result> ret;
	int i = 0;
    while(i < s.size()){
        string tmp="";
		while(i < s.size()) {
			tmp += s[i];
			i++;
			if(tmp.size() >= 2 && (i >= s.size() || (s[i] >= '0' && s[i] <= '9'))) break;
		}
		// cout << "\'" << tmp << "\'" << endl;
        Result result;
        result.score = (int)(tmp[0] - '0');
		if(tmp[1] == '0') {
			result.score = 10;
			tmp = tmp.substr(1);
		}
        result.bonus = tmp[1];
        if(tmp.size()>=3)
            result.option = tmp[2];
        else result.option = ' ';
        ret.push_back(result);
    }
    return ret;
}

int getBonusPow(char c) {
    if(c=='S') return 1;
    if(c=='D') return 2;
    return 3;
}

int solution(string dartResult) {
    int answer = 0;
    int scores[3] = {0};
    vector<Result> results = getResults(dartResult);
    for(int i = 0; i < 3; i++) {
        scores[i] = pow(results[i].score, getBonusPow(results[i].bonus));
        int option = 1;
        if(i < 2 && results[i+1].option == '*') {
			option *= 2;
		}
        if(results[i].option == '*') {
			option *= 2;
		} else if (results[i].option == '#') {
			option *= -1;
		}
        scores[i] *= option;
    }
	// cout << scores[0] << ' ' << scores[1] << ' ' << scores[2] << endl;
    return scores[0] + scores[1] + scores[2];
    // return results[0].score;
}
