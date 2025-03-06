#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#define INF 987654321

using namespace std;

int n, m;
map<string, int> kingdom;
int arr[2000];

int getParent(int a) {
	if (a != arr[a]) return arr[a] = getParent(arr[a]);
	return a;
}

void unionKingdom(int win, int lose) {
	int pa = getParent(win);
	int pb = getParent(lose);
	if (pa == pb && pb == lose) { // 속국이 종주국을 이긴 경우
		arr[win] = win;
		arr[pb] = win;
	}
	else {
		arr[pb] = pa;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i < 2000; i++) { arr[i] = i; }
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		kingdom.insert({ s, i });
	}
	for (int i = 0; i < m; i++) {
		vector<string> dir;
		string s, buffer;
		getline(cin, s);
		istringstream ss(s);
		while (getline(ss, buffer, ',')) {
			dir.push_back(buffer);
		}
		string win = dir[0];
		string lose = dir[1];
		if (dir[2][0] == '2') {
			swap(win, lose);
		}
		unionKingdom(kingdom.at(win), kingdom.at(lose));
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == i) ans++;
	}
	cout << ans << '\n';
	for (map<string, int>::iterator iter = kingdom.begin(); iter != kingdom.end(); iter++) {
		//cout << iter->first << " " << iter->second << " " << getParent(iter->second) << endl;
		if (iter->second == getParent(iter->second)) {
			cout << iter->first << '\n';
		}
	}

	return 0;
}