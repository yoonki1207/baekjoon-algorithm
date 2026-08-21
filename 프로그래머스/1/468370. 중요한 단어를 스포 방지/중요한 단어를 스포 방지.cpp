#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
/*
# data structure
- hash_map [key, value]: [word, count]
message에 word가 몇 번 등장하는지 센다.

- array [index, value]: [_, word_index]
index에 존재해는 word의 word_index이다
word_index는 해당 word가 message의 몇 번째로 등장하는지 알려준다.
arr[index] == -1 이라면, 공백이다.

- words [index, value]: [word_index, word]
*/

vector<int> arr;
vector<string> words;
map<string, int> m;

void init_arr(const string message, const int arr_n) {
    arr = vector<int>(arr_n);
    int cnt = 0;
    int start_index = 0;
    int i = 0;
    if(message[0] == ' ') {
        i = 1;
        arr[0] = -1;
        start_index = 1;
    }
    for(; i < arr_n; i++) {
        if(message[i] == ' ') {
            arr[i] = -1;
            string word = message.substr(start_index, i-start_index);
            words.push_back(word);
            map<string, int>::iterator iter = m.find(word);
            if(iter != m.end()) {
                ++iter->second;
            } else {
                m.insert({word, 0});
            }
            start_index = i + 1;
            cnt++;
            continue;
        } else {
            arr[i] = cnt;
        }
    }
    string word = message.substr(start_index, message.size()-start_index);
    words.push_back(word);
    map<string, int>::iterator iter = m.find(word);
    if(iter != m.end()) {
        ++iter->second;
    } else {
        m.insert({word, 0});
    }
}

void trim_ref(string& message) { // trim
    if(message[0] == ' ') message = message.substr(1);
    if(message[message.size()-1] == ' ') 
        message = message.substr(0, message.size()-1);
}

int solution(string message, vector<vector<int>> spoiler_ranges) {
    // trim_ref(message);
    init_arr(message, message.size());
    vector<string> spoiler_words;
    vector<bool> is_spoiler_word(words.size(), false); // [word_index, is_spoiler_word]
    map<string, bool> m_visited_word;
    int ans = 0;
    // calc spoiler_words
    for(int i = 0; i < spoiler_ranges.size(); i++) {
        int start_index = spoiler_ranges[i][0];
        int end_index = spoiler_ranges[i][1];
        for(int j = start_index; j <= end_index; j++) {
            if(arr[j] != -1) {
                is_spoiler_word[arr[j]] = true;
            }
        }
    }
    
    // add visited word with non-spoiler words
    for(int index = 0; index  < words.size(); index++) {
        if(!is_spoiler_word[index]) {
            m_visited_word.insert({words[index], true});
        }
    }
    
    for(int index = 0; index < words.size(); index++) {
        if(is_spoiler_word[index]) {
            map<string, bool>::iterator iter = m_visited_word.find(words[index]);
            if(iter == m_visited_word.end()) {
                ++ans;
                m_visited_word.insert({words[index], true});
            }
        }
    }
    
    return ans;
}

/*
here is muzi here is a secret message
0123456789012345678901234567890123456
[  ]                   [    ]
*/