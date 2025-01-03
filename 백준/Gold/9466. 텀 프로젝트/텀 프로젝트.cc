#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int t;

vector<int> findTeam(int index, const vector<int>& v, vector<bool>& visited, vector<int>& s, vector<int>& hasTeam) {
	// cout << "Index: " << index << endl;
	vector<int> ret;

	if(visited[index]) { // 이미 방문했다면, 순환 생성 후 리턴
		ret.push_back(index);
		while(!s.empty() && s.back() != index) {
			ret.push_back(s.back());
			s.pop_back();
		}
		return ret;
	}
	if(hasTeam[index] == -1) return ret;
	hasTeam[index] = -1;
	s.push_back(index);
	visited[index] = true;
	
	ret = findTeam(v[index], v, visited, s, hasTeam);

	visited[index] = false;
	s.pop_back();
	return ret;
}

int solve(const vector<int>& v) {
	int n = v.size();
	vector<int> hasTeam(n, 0);
	// cout << hasTeam.size() << "!!!\n";
	for(int i = 0; i < n; i++) {
		// cout << "loop: " << i << endl;
		vector<bool> visited(n, false);
		vector<int> s;
		if(hasTeam[i] == 1 || hasTeam[i] == -1) continue;
		vector<int> team = findTeam(i, v, visited, s, hasTeam);
		// cout << '>' << team.size() << endl;
		if(hasTeam[i] == -1) {
			//역행하여 모두 -1로 만들기.
			
		}
		for(vector<int>::iterator iter = team.begin(); iter != team.end(); iter++) {
			// cout << *iter << ' ';
			hasTeam[*iter] = 1;
		} 
		// cout << endl;
	}

	// count number of 'false' in vector
	int ret = 0;
	for(vector<int>::iterator iter = hasTeam.begin(); iter != hasTeam.end(); iter++) if(*iter == -1) ++ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> t;
	while(t-->0) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) {
			cin >> v[i]; --v[i];
		}
		cout << solve(v) << endl;
	}
	return 0;
}


// 기저 1: 어떤 점에서 시작하면 항상 순환을 발견한다.
// 기저 2: 순환을 발견하면 순환을 제외한 연결된 모든 점은 순환될 수 없다.