#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <string>
#define INF 987654321
#define lld long long
#define MAX_N 1000001

using namespace std;

map<string, bool> visitedSet;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int K, N;
	cin >> N >> K;
	char v;
	string s = "";
	for(int i = 0; i < N;i ++) {
		cin >> v;
		s += v;
	}
	string originS = s;
	sort(originS.begin(), originS.end());
	queue<pair<int, string>> q;
	int ans = -1;
	q.push({0, s});
	while(!q.empty()) {
		int t = q.front().first;
		string cs = q.front().second;
		if(cs == originS) {
			ans = t;
			break;
		}
		// visitedSet.insert({cs, true});
		q.pop();
		if(visitedSet[cs] == true) continue;
		visitedSet[cs] = true;
		for(int i = 0; i <= N - K; i++) {
			string num1 = cs.substr(0,i);
			string num2 = cs.substr(i, K);
			reverse(num2.begin(), num2.end());
			string num3 = cs.substr(K+i,N);
			// if(visitedSet.find(num1+num2+num3) != visitedSet.end()) continue;
			q.push({t+1, num1+num2+num3});
		}
	}
	cout << ans << endl;
	
	return 0;
}