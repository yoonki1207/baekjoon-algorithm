#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#define lld long long int
#define MAX_N 10000002

using namespace std;

void printFan() {
	cout << ":fan:";
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	string s;
	cin >> s;
	printFan();
	printFan();
	printFan();
	cout << '\n';
	printFan();
	cout << ":" << s << ":";
	printFan();
	cout << '\n';
	printFan();
	printFan();
	printFan();
	return 0;
}