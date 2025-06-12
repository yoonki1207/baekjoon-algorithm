#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#define INF 987654321
#define lld long long
#define ull unsigned long long
#define MAX_N 500000

using namespace std;

const char* numbers[5] = {
"###...#.###.###.#.#.###.###.###.###.###",
"#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
"#.#...#.###.###.###.###.###...#.###.###",
"#.#...#.#.....#...#...#.#.#...#.#.#...#",
"###...#.###.###...#.###.###...#.###.###",};

int N;
char arr[5][39];

vector<int> getNumberSet(int index) {
	vector<int> possibleNumber;
	for(int n = 0; n < 10; n++) {
		bool isPossible = true;
		// 문자가 켜져있으면서 대응되는게 꺼져있음녀 안됨
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 3; j++) {
				if(arr[i][index*4+j] == '#' && 
					numbers[i][n*4+j] == '.') {
					isPossible = false;
				}
			}
		}
		if(isPossible) possibleNumber.push_back(n);
	}
	return possibleNumber;
}
// a bc def

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for(int i = 0; i < 5; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < N*3+N-1; j++) {
			arr[i][j] = s[j];
		}
	}
	double ans = 0.0;
	lld repeated = 1;
	vector<vector<int>> res(N);
	for(int i = 0; i < N; i++) {
		res[i] = getNumberSet(i);
		if(res[i].size() == 0) {
			cout << "-1" << endl;
			return 0;
		}
	}
	for(int i = 0; i < N; i++) {
		repeated = repeated * res[i].size();
	}
	for(int i = 0; i < N; i++) {
		lld numbers = 0;
		for(int j = 0; j < res[i].size(); j++) {
			numbers += res[i][j];
		}
		numbers *= repeated/res[i].size()*powl(10l, N-i-1);
		ans += (double)numbers/repeated;
	}
	cout << fixed;
	cout.precision(6);
	cout << ans << endl;

	
	return 0;
}
