#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
bool arr[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long int min, max;

	cin >> min >> max;
	long long int i = 2;
	int ans = max - min + 1;
	while (i * i <= max) {
		long long int n = min / (i * i);
		if (min % (i * i) != 0)n++;
		while (n * (i * i) <= max) {
			if (!arr[n * (i * i) - min]) {
				arr[n * (i * i) - min] = true;
				ans--;
			}
			n++;
		}
		i++;
	}

	cout << ans;

	return 0;
}