#include <string>
#include <vector>

using namespace std;

int networks[200];
int k = 0;

void dfs(int node, const vector<vector<int>>& computers, int k) {
    const vector<int>& connections = computers[node];
    for(int i = 0; i < connections.size(); i++) {
        if(i == node) continue;
        networks[node] = k;
        if(connections[i] == 1 && networks[i] == -1) {
            dfs(i, computers, k);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++) networks[i] = -1;
    bool visited[200];
    for(int i = 0; i < n; i++) {
        if(networks[i] != -1) continue;
        ++k;
        dfs(i, computers, k);
    }
    
    return k;
}