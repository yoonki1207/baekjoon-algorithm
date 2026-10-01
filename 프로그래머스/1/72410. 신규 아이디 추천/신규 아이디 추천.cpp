#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool is_valid(const string& name) {
    if(name.size() < 3 || name.size() > 15) return false;
    for(int i = 0; i < name.size(); i++) {
        if(!(name[i] == '-' || name[i] == '_' || name[i] == '.' ||
            (name[i] >= 'a' && name[i] <= 'z') || 
            (name[i] >= '0' && name[i] <= '9'))) return false;
    }
    if(name[0] == '.' || name[name.size()-1] == '.') return false;
    for(int i = 1; i < name.size(); i++) {
        if(name[i] == '.' && name[i] == name[i-1]) return false;
    }
    return true;
}

string convert(string name) {
    // #1
    for(int i = 0; i < name.size(); i++) {
        char& c = name[i];
        if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    }
    // #2
    string str;
    int offset = 0, cnt = 0;
    for(int i = 0; i < name.size(); i++) {
        cnt++;
        if(!(name[i] == '-' || name[i] == '_' || name[i] == '.' ||
            (name[i] >= 'a' && name[i] <= 'z') || 
            (name[i] >= '0' && name[i] <= '9'))) {
            // cout << "!";
            str += name.substr(offset, cnt - 1);
            offset = i + 1;
            cnt = 0;
        }
    }
    str += name.substr(offset);
    
    // #3
    name = str;
    int pos = 1;
    str = "";
    for(int i = 0; i < name.size() - 1; i++) {
        if(name[i] == '.' && name[i] == name[i + 1]) continue;
        str += name[i];
    }
    str += name.back();
    
    name = str;
    // #4, 5
    if(name[0] == '.') name = name.substr(1);
    if(name.back() == '.') name = name.substr(0, name.size() - 1);
    if(name.size() == 0) return "aaa";
    // #6
    if(name.size() >= 16) {
        name = name.substr(0, 15);
        if(name.back() == '.') name = name.substr(0, name.size() - 1);
    }
    // #7
    if(name.size() <= 2) {
        while(name.size() < 3) {
            name.push_back(name.back());
        }
    }
    
    return name;
}

string solution(string new_id) {
    string answer = "ASD";
    return convert(new_id);
}