#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321

using namespace std;

int n;
int arr[512];
int p[50];

void init() {
    int val = 1;
    for(char c = 'a'; c <= 'z'; c++) {
        arr[c] = val++;
    }
    for(char c = 'A'; c <= 'Z'; c++) {
        arr[c] = val++;
    }
    for(int i = 0; i < 50; i++) {
        p[i] = i;
    }
}

int getParent(int x) {
    if(x != p[x]) return p[x] = getParent(p[x]);
    return x;
}

void unionNode(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);
    if(pa != pb) p[pa] = getParent(pb);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    init();
    int totalLan = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            if(i != j && s[j] != '0')
                pq.push({arr[s[j]], {i, j}});
            totalLan += arr[s[j]];
        }
    }

    int usedLan = 0;
    while(!pq.empty()) {
        int d = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        if(getParent(a) != getParent(b)) {
            unionNode(a, b);
            usedLan += d;
        }
    }
    bool isAllConnected = true;
    int p = getParent(0);
    for(int i = 0; i < n; i++) {
        if(p != getParent(i)) {
            isAllConnected = false;
        }
    }
    if(isAllConnected == false) {
        cout << "-1";
    } else {
        cout << totalLan - usedLan;
    }

	return 0;
}