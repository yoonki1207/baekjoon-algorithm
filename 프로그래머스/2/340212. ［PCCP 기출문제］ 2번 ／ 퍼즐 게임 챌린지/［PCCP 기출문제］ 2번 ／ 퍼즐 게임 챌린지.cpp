#include <string>
#include <vector>

using namespace std;

long long solveTime(int index, int level, vector<int>& diffs, vector<int>& times) {
    if(index == 0) return times[0];
    int diff = diffs[index] - level;
    if(diff > 0) {
        return (times[index-1] + times[index])*diff + times[index];   
    } else {
        return times[index];
    }
}

bool isPossible(int level, vector<int>& diffs, vector<int>& times, const long long& limit) {
    long long total = 0;
    bool is_possible = true;
    for(int i = 0; i < diffs.size(); i++) {
        long long t = solveTime(i, level, diffs, times);
        total += t;
        if(total > limit) is_possible = false;
    }
    return is_possible;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int max_level = 1;
    for(int i = 0; i < diffs.size(); i++) {
        max_level = max_level > diffs[i] ? max_level : diffs[i];
    }
    int l = 1, r = max_level + 1;
    while(l < r) {
        int m = (l+r)/2;
        bool is_possible = isPossible(m, diffs, times, limit);
        if(is_possible) {
            r = m;
        } else {
            l = m+1;
        }
    }
    return r;
}