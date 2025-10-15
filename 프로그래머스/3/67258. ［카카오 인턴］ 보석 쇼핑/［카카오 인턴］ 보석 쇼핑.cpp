#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map<string, int> m;
    for(vector<string>::iterator iter = gems.begin(); iter != gems.end(); iter++) {
        if(m.find(*iter) == m.end()) {
            m.insert({*iter, 0});
        }
    }
    int left = 0, right = 0, cnt = 0, len = 987654321;
    queue<string> q;
    for(int i = 0; i < gems.size(); i++) {
        q.push(gems[i]);
        map<string, int>::iterator iter = m.find(gems[i]);
        iter->second++;
        if(iter->second == 1) cnt++;
        if(cnt == m.size() && q.size() < len) {
            answer[1] = i+1;
            answer[0] = i+1-q.size()+1;
            len = q.size();
        }
        while(cnt >= m.size()) {
            string s = q.front();
            q.pop();
            iter = m.find(s);
            iter->second--;
            if(iter->second == 0) {
                cnt--;
            }
            if(cnt == m.size() && q.size() < len) {
                answer[1] = i+1;
                answer[0] = i+1-q.size()+1;
                len = q.size();
            }
        }
    }
    return answer;
}