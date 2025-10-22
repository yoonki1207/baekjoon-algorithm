#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#define INF 987654321
#define lld long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<char> directions;
	vector<string> destinations;
	while (true) {
		char dir;
		string destination;
		cin >> dir >> destination;
		directions.push_back(dir);
		destinations.push_back(destination);
		if (destination.compare("SCHOOL") == 0) break;
	}
	for (int i = destinations.size() - 2; i >= 0; --i) {
		string dir = directions[i + 1] == 'R' ? "LEFT" : "RIGHT";
		cout << "Turn " << dir << " onto " << destinations[i] << " street.\n";
	}
	cout << "Turn " << (directions[0] == 'R' ? "LEFT" : "RIGHT") <<
		" into your HOME.\n";
	return 0;
}
