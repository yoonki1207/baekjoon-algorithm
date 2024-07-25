#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <unordered_map>
#define MAX_N 200001

using namespace std;

unordered_map<string, int> m;
int parent[MAX_N];
int nFriends[MAX_N];
int next_index;

int getParent(int node) {
    if(parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}

int getNode(const string& name) {
    if(m.find(name) == m.end()) {
        m.insert({name, next_index});
        return next_index++;
    } else {
        return m.at(name);
    }
}

int main() { // 98%에서 틀렸습니다...
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T; cin >> T;
    while(T-->0) {
        int n;
        cin >> n;
        for(int i = 0; i < n*2 + 1; i++) {
            parent[i] = i;
            nFriends[i] = 1;
        }
        for(int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;
            // union
            int node_a = getNode(a);
            int node_b = getNode(b);
            int parent_a = getParent(node_a);
            int parent_b = getParent(node_b);
            if(parent_a != parent_b) {
                parent[parent_b] = parent_a;
                nFriends[parent_a] += nFriends[parent_b];
            }
            cout << nFriends[parent_a] << '\n';
        }
    }
    return 0;
}