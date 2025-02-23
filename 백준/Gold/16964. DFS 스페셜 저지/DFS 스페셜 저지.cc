#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <map>
#define INF 987654321

using namespace std; 

map<pair<int, int>, bool> m;
vector<int> vLen;
vector<int> v;
bool ans;

int n;

int checkDfs(int index) { // 탐색한 갯수를 반환한다.
    int curr = v[index];
    int next_index = index + 1;
    while(next_index < v.size()) {
        int next = v[next_index];
        if(m.find({curr, next}) != m.end()) {
            int len = checkDfs(next_index);
            next_index += len;
        } else {
            // next_index = next_index - index;
            break;
        }
    }
    // cout << curr << ": " << next_index-index << endl;
    return next_index - index;
}

int main()
{
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    cin >> n;
    // n = 100000;/
    v = vector<int>(n);
    vLen = vector<int>(n+1);
    ans = true;
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        // a = i+1, b = i+2;
        vLen[a]++;
        vLen[b]++;
        m.insert({{a, b}, true});
        m.insert({{b, a}, true});
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        // v[i] = i+1;
    }

    vector<int> s;
    bool ans = true;
    s.push_back(v[0]);
    if(v[0] != 1) ans = false;
    for(int i = 1; i < n; i++) {
        int next_node = v[i];
        while(!s.empty() && m.find({s.back(), next_node}) == m.end()) {
            s.pop_back();
        } 
        if(s.empty()) {
            ans = false;
            break;
        }
        s.push_back(next_node);
    }
    if(s.empty()) ans = false;

    cout << (ans ? 1 : 0) << endl;
    

    return 0;
}
/*
         -1    3    1    2    4   -1
dp[n][1] -1    3    4    6    10  10
dp[n][2] -INF  -INF 0    5    8   
*/