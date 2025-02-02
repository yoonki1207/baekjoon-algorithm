#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int getParent(vector<int>& graph, int a) {
    if(graph[a] != a) return graph[a] = getParent(graph, graph[a]);
    else return a;
}

void unionNode(vector<int>& graph, int a, int b) {
    int pa = getParent(graph, a);
    int pb = getParent(graph, b);
    if(pa < pb) graph[pb] = graph[pa];
    else graph[pa] = graph[pb];
}

bool isSameSet(vector<int>& graph, int a, int b) {
    return getParent(graph, a) == getParent(graph, b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> computers(n+1);
    for(int i = 0; i < n; i++) computers[i] = i;
    int m; cin >> m;
    vector<pair<int, pair<int, int>>> v(m);
    for(int i = 0; i < m; i++) {
        cin >> v[i].second.first >> v[i].second.second >> v[i].first;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < v.size(); i++) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        if(!isSameSet(computers, a, b)) {
            ans += v[i].first;
            unionNode(computers, a, b);
        }
    }
    cout << ans;
    return 0;
}