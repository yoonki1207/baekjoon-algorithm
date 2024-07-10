#include <string>
#include <vector>

using namespace std;

int g_output[1000001];
int g_input[1000001];

vector<int> checkGraph(vector<vector<int>> nodes) {
    vector<int> ret(4,0);
    for(int i = 1; i <= nodes.size(); i++) {
        if(g_output[i] >= 2 && g_input[i] == 0) ret[0] = i;
        if(g_output[i] == 0 && g_input[i] >= 1) ret[2]++;
        if(g_output[i] == 2 && g_input[i] >= 2) ret[3]++;
    }
    return ret;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    vector<vector<int>> nodes(edges.size()+2);
    for(auto iter = edges.begin(); iter != edges.end(); iter++) {
        nodes[iter->at(0)].push_back(iter->at(1));
        g_output[iter->at(0)]++;
        g_input[iter->at(1)]++;
    }
    // 들어오는 간선이 없고 나가는 간선이 2개 이상 있으면 그 노드가 keyNode이다.
    answer = checkGraph(nodes);
    answer[1] = nodes[answer[0]].size()-answer[2]-answer[3];
    
    return answer;
}