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

using namespace std;

/* Definitions */
typedef struct {
	string s1;
	string s2;
	string s3;
} Hanoi;

Hanoi hanoi;
set<pair<string, pair<string, string>>> visited;


/* Functions */
bool isAllChar(const string& s, const char& c) {
	for(int i = 0; i < s.size(); i++)
		if(s[i] != c) return false;
	return true;
}

bool checkValid(Hanoi tower) {
	return
		isAllChar(tower.s1, 'A') && 
		isAllChar(tower.s2, 'B') &&
		isAllChar(tower.s3, 'C');
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int i = 0; i < 3; i++) {
		int n;
		cin >> n;
		string s;
		if(n)
		cin >> s;
		
		switch (i) {
			case 0:
				hanoi.s1 = s;
			break;
			case 1:
				hanoi.s2 = s;
			break;
			case 2:
				hanoi.s3 = s;
			break;
			default:
			break;
		}
	}
	// visited.insert({hanoi.s1, {hanoi.s2, hanoi.s3}});
	// if(visited.find({hanoi.s1, {hanoi.s2, hanoi.s3}}) != visited.end()) {
	// 	cout << "Exsist";
	// } else {
	// 	cout << "No";
	// }
	queue<pair<int, Hanoi>> q;
	q.push({0, hanoi});
	while(!q.empty()) {
		int cnt = q.front().first;
		Hanoi tower = q.front().second;
		q.pop();
		// if exsist
		// cout << cnt << endl << tower.s1 << endl << tower.s2 << endl << tower.s3 << endl;
		if(visited.find({tower.s1, {tower.s2, tower.s3}}) != visited.end()) {
			continue;
		} else {
			visited.insert({tower.s1, {tower.s2, tower.s3}});
		}
		// cout << "!" << endl;
		if(checkValid(tower)) {
			cout << cnt << endl;
			break;
		}
		if(tower.s1.length() > 0) {
			Hanoi next;
			char t = tower.s1[tower.s1.size()-1];
			next.s1 = tower.s1.substr(0, tower.s1.size()-1);
			next.s2 = tower.s2;
			next.s3 = tower.s3;
			q.push({cnt+1, {next.s1, next.s2+t, next.s3}});
			q.push({cnt+1, {next.s1, next.s2, next.s3+t}});
		}
		if(tower.s2.length() > 0) {
			Hanoi next;
			char t = tower.s2[tower.s2.size()-1];
			next.s1 = tower.s1;
			next.s2 = tower.s2.substr(0, tower.s2.size()-1);
			next.s3 = tower.s3;
			q.push({cnt+1, {next.s1+t, next.s2, next.s3}});
			q.push({cnt+1, {next.s1, next.s2, next.s3+t}});
		}
		if(tower.s3.length() > 0) {
			Hanoi next;
			char t = tower.s3[tower.s3.size()-1];
			next.s1 = tower.s1;
			next.s2 = tower.s2;
			next.s3 = tower.s3.substr(0, tower.s3.size()-1);
			q.push({cnt+1, {next.s1+t, next.s2, next.s3}});
			q.push({cnt+1, {next.s1, next.s2+t, next.s3}});
		}
	}
	
	return 0;
}