#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sort_by_index = 0;

int getIndex(string s) {
    if(s.compare("code") == 0) return 0;
    if(s.compare("date") == 0) return 1;
    if(s.compare("maximum") == 0) return 2;
    return 3;
}

bool customSort(const vector<int>& a, const vector<int>& b) {
    return a[sort_by_index] < b[sort_by_index];
}

// code, date, maximum, remain
vector<vector<int>> solution(
    vector<vector<int>> data, 
    string ext, 
    int val_ext, 
    string sort_by
    ) {
    vector<vector<int>> answer;
    int col_index = getIndex(ext);
    for(auto iter = data.begin(); iter != data.end(); iter++) {
        if((*iter)[col_index] < val_ext) {
            answer.push_back(*iter);
        }
    }
    sort_by_index = getIndex(sort_by);
    sort(answer.begin(), answer.end(), customSort);
    return answer;
}