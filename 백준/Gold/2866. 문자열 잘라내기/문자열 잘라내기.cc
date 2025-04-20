#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int R, C;
map<string, int> m;
vector<string> v;
char arr[1000][1000];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for(int i = 0; i < R; i++) {
		string s; cin >> s;
		for(int j = 0; j < C; j++) {
			arr[i][j] = s[j];
		}
	}
	for(int i = 0; i < C; i++) {
		string s;
		for(int j = 0; j < R; j++) {
			s += arr[j][i];
		}
		v.push_back(s);
	}
	bool isOver = false;
	int i = 0;
	for(i = 0; i < R-1; i++) {
		m.clear();
		for(int j = 0; j < C; j++) {
			string s = v[j].substr(i+1, R-i-1);
			if(m.find(s) != m.end()) {
				isOver = true;
				break;
			}
			m.insert({s, i});
		}
		if(isOver) break;
	}
	cout << i << endl;
	return 0;
}