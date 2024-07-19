#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n;
int ans;
typedef struct Class {
    int n;
    int s;
    int e;
} Class;

struct cmp {
    bool operator()(const Class a, const Class b) {
        return a.s > b. s;
    }
};
struct cmp2 {
    bool operator()(const Class a, const Class b) {
        return a.e > b.e;
    }
};

priority_queue<Class, vector<Class>, cmp> q;
priority_queue<Class, vector<Class>, cmp2> v;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int n, s, e;
        cin >> n >> s >> e;
        q.push({n, s, e});
    }
    while(!q.empty()) {
        Class top = q.top();
        q.pop();
        if(v.empty()) {
            v.push(top);
        } 
        else {
            Class t = v.top();
            if(t.e <= top.s) {
                v.pop();
            } else {
                ans++;
            }
                v.push(top);
        }
    }
    cout << ans + 1;
    return 0;
}