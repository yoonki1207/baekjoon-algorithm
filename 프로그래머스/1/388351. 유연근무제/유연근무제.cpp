#include <string>
#include <vector>

using namespace std;

inline bool is_weekends(int day) {
    return (day-1)%7 == 5 || (day-1)%7 == 6;
}

inline int add_10_min(int t) {
    int ret = t + 10;
    if(ret % 100 >= 60) {
        int h = ret / 100;
        h += 1;
        ret -= 60;
        ret = h * 100 + ret%100;
    }
    return ret;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i = 0; i < schedules.size(); i++) {
        int time = schedules[i];
        bool eligible = true;
        vector<int>& timelog = timelogs[i];
        int index = 0;
        for(int day = startday; day < startday + 7; day++, index++) {
            if(is_weekends(day)) continue;
            if(timelog[index] > add_10_min(time)) {
                eligible = false;
                break;
            }
        }
        
        if(eligible) answer++;
    }
    return answer;
}