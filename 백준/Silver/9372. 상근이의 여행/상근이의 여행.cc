#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

int T, N, M;
vector<int> arr;

int getParent(int a) {
	if(a != arr[a]) return arr[a] = getParent(arr[a]);
	return a;
}

void unionNode(int a, int b) {
	int pa = getParent(a);
	int pb = getParent(b);
	if(pa != pb) arr[pa] = getParent(pb);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> T;
	while(T-->0) {
		cin >> N >> M;
		arr = vector<int>(N+1);
		for(int i = 0; i < arr.size(); i++) arr[i] = i;
		int cnt = 0;
		for(int i = 0; i < M; i++) {
			int a, b; cin >> a >> b;
			if(getParent(a) != getParent(b)) {
				cnt++;
				unionNode(a, b);
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
