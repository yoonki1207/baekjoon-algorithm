#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#include <string.h>
#include <time.h>
#define INF 987654321
#define lld long long int
#define pii pair<int, int>
#define pdd pair<double, double>
// #define DEBUG
// #define MOD 1000000009

using namespace std;

/*
백준 
*/
int K, L;
map<string, int> student;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> K >> L;
    string s;
    for(int i = 0; i < L; ++i) {
        cin >> s;
        map<string, int>::iterator iter = student.find(s);
        if(iter == student.end()) {
            student.insert({s, i});
        } else {
            iter->second = i;
        }
    }
    vector<pair<int, string>> v(student.size());
    int idx = 0;
    for(pair<string, int> stu: student) {
        v[idx++] = {stu.second, stu.first};
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < min((size_t)K, v.size()); i++) {
        cout << v[i].second << '\n';
    }
    return 0;
}