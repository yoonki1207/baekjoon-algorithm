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

int arr[8][8];
pair<int, int> king_coord, stone_coord;

// int setStone(char col, int row, int stone) {
// 	int c = col-'A';
// 	int r = row-1;
// 	arr[r][c] = stone;
// }

void init(string k, string s) {
	king_coord.first = k[0]-'A';
	king_coord.second = k[1]-'1';
	stone_coord.first = s[0]-'A';
	stone_coord.second = s[1]-'1';
}

bool checkRange(int c, int r) {
	return c < 8 && c >= 0 && r < 8 && r >= 0;
}

void moveKing(string move) {
	int y, x;
	y = x = 0;
	if(move.compare("R") == 0) {
		x = 1;
	} else if(move.compare("L") == 0) {
		x = -1;
	} else if(move.compare("T") == 0) {
		y = 1;
	} else if(move.compare("B") == 0) {
		y = -1;
	} else if(move.compare("RT") == 0) {
		x = 1;
		y = 1;
	} else if(move.compare("LT") == 0) {
		x = -1;
		y = 1;
	} else if(move.compare("RB") == 0) {
		x = 1;
		y = -1;
	} else if(move.compare("LB") == 0) {
		x = -1;
		y = -1;
	}
	if(king_coord.first + x == stone_coord.first && king_coord.second + y == stone_coord.second) {
		if(checkRange(stone_coord.first + x, stone_coord.second + y)) {
			stone_coord.first += x;
			stone_coord.second += y;
			king_coord.first += x;
			king_coord.second += y;
		} 
	} else if(checkRange(king_coord.first + x, king_coord.second + y)) {
		king_coord.first += x;
		king_coord.second += y;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string K, S;
	int N;
	cin >> K >> S >> N;
	init(K, S);
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		moveKing(s);
	}

	cout << (char)(king_coord.first+'A') << king_coord.second+1 << endl;
	cout << (char)(stone_coord.first+'A') << stone_coord.second+1 << endl;
	return 0;
}

// 10 9 8 7 6