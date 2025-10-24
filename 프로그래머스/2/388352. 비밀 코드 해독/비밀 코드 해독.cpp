#include <string>
#include <vector>

using namespace std;

// 30 c 5 = 29*7*27*26 = 142506 // 142506 * 10 * 5 = 대충 14만 * 15 = 1000만도 안됨. 즉, do brute force

int N;
int answer;

int countMatch(const vector<int>& a, const vector<int>& b) {
    int i = 0, j = 0, ret = 0;
    while(i < a.size() && j < b.size()) {
        if(a[i] == b[j]) {
            ret++;
            i++;
            j++;
        } else if(a[i] < b[j]){
            i++;
        } else {
            j++;
        }
    }
    return ret;
}

void dfs(int prev, vector<int>& v, const vector<vector<int>>& q, const vector<int>& ans) {
    if(v.size() == 5) {
        bool possible = true;
        for(int i = 0; i < q.size(); i++) {
            if(countMatch(q[i], v) != ans[i]) {
                possible = false;
            }
        }
        if(possible) answer++;
        return;
    }
    for(int i = prev+1; i <= N; i++) {
        v.push_back(i);
        dfs(i, v, q, ans);
        v.pop_back();
    }
}


int solution(int n, vector<vector<int>> q, vector<int> ans) {
    N = n;
    vector<int> v;
    dfs(0, v, q, ans);
    return answer;
}