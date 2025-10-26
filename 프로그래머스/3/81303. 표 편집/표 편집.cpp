#include <string>
#include <vector>

using namespace std;

struct Node {
    Node* prev;
    Node* next;
    int val;
};

vector<Node*> stk;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    Node* head = new Node();
    head->prev = head->next = nullptr;
    head->val = 0;
    Node* curr = head;
    Node* cursor = head;
    for(int i = 1; i < n; i++) {
        Node* next = new Node();
        next->prev = curr;
        curr->next = next;
        next->next = nullptr;
        next->val = i;
        curr = next;
        if(k == i) cursor = curr;
    }
    // init end
    for(vector<string>::iterator iter = cmd.begin(); iter != cmd.end(); iter++) {
        if((*iter)[0] == 'U') {
            int cnt = stoi((*iter).substr(2, -1));
            while(cnt--) cursor = cursor->prev;
        } else if((*iter)[0] == 'D') {
            int cnt = stoi((*iter).substr(2, -1));
            while(cnt--) cursor = cursor->next;
        } else if((*iter)[0] == 'C') {
            stk.push_back(cursor);
            if(cursor->next == nullptr) {
                cursor = cursor->prev;
                cursor->next = nullptr;
            } else {
                if(cursor->prev != nullptr) {
                    cursor->prev->next = cursor->next;   
                } 
                cursor->next->prev = cursor->prev;
                cursor = cursor->next;
            }
        } else { // Z
            if(!stk.empty()) {
                Node* undo = stk.back();
                stk.pop_back();
                if(undo->prev != nullptr) undo->prev->next = undo;
                if(undo->next != nullptr) undo->next->prev = undo;
            }
        }
    }
    while(cursor->prev != nullptr) {
        cursor = cursor->prev;
    }
    curr = cursor;
    for(int i = 0; i < n; i++) {
        answer += 'X';
    }
    while(curr != nullptr) {
        answer[curr->val] = 'O';
        curr = curr->next;
    }
    return answer;
}