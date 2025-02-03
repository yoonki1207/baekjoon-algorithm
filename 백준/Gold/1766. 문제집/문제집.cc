#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define lld long long

using namespace std;

int n, m;

class Node {
public:
	int num;
	int degree;
	vector<Node*> to;
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<Node*> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = new Node();
		v[i]->num = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; --a; --b;
		v[a]->to.push_back(v[b]);
		v[b]->degree++;
	}
	priority_queue<int, vector<int>, greater<>> q;
	for (int i = 0; i < n; i++) {
		if (v[i]->degree == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		Node* node = v[q.top()];
		cout << node->num + 1 << ' ';
		q.pop();
		for (vector<Node*>::iterator iter = node->to.begin(); iter != node->to.end(); iter++) {
			((*iter)->degree)--;
			if ((*iter)->degree == 0) {
				q.push((*iter)->num);
			}
		}
	}
	return 0;
}
