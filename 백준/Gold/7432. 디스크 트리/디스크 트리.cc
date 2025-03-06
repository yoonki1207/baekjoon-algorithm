#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#define INF 987654321

using namespace std;

int n;
typedef struct Node {
	map<string, Node*> m;
}Node;

vector<string> split(const string& s, char t) {
	int prev_index = 0;
	int next_index = 0;
	int cnt = 0;
	vector<string> ret;
	for (; next_index < s.size(); next_index++) {
		if (s[next_index] == t) {
			ret.push_back(s.substr(prev_index, next_index - prev_index));
			prev_index = next_index + 1;
		}
	}
	ret.push_back(s.substr(prev_index));
	return ret;
}

void print(Node* node, int depth) {
	for (map<string, Node*>::iterator iter = node->m.begin(); iter != node->m.end(); iter++) {
		for (int i = 0; i < depth; i++) cout << ' ';
		cout << iter->first << '\n';
		if (iter->second->m.empty() == false) {
			print(iter->second, depth+1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	Node* root = new Node();
	for (int i = 0; i < n; i++) {
		string s, buffer;
		cin >> s;
		Node* curr = root;
		vector<string> dir;
		istringstream ss(s);
		while (getline(ss, buffer, '\\')) {
			dir.push_back(buffer);
		}
		for (vector<string>::iterator iter = dir.begin(); iter != dir.end(); iter++) {
			if (curr->m.find(*iter) == curr->m.end()) {
				curr->m.insert({ *iter, new Node()});
			}
			curr = curr->m.at(*iter);
		}
	}
	print(root, 0);
	return 0;
}