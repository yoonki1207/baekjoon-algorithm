#include <iostream>
#include <string>

using namespace std;

//bool solve(int* arr, int n) {
//	if (n <= 1) return true;
//	int mid = n / 2;
//	int left_mid = n / 2 / 2;
//	int right_mid = mid + left_mid + 1;
//	if (arr[left_mid] != arr[right_mid]) {
//		return solve(arr, mid) && solve(arr + mid + 1, mid);
//	}
//	else {
//		return false;
//	}
//}
bool solve(int* arr, int left, int right) {
	if (right - left <= 1) {
		return true;
	}
	int mid = (left + right) / 2;
	for (int i = left; i < mid; i++) {
		if (arr[i] == arr[right - i]) return false;
	}
	return solve(arr, left, mid - 1) && solve(arr, mid + 1, right);
}
// 012 3 456
// 100 0 110
// 100 0 011

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		string s;
		bool isPossible = true;
		cin >> s;


		int arr[3000] = { 0 };
		for (int i = 0; i < s.size(); i++) arr[i] = (int)(s[i]-'0');
		isPossible = solve(arr, 0, s.size()-1);
		string ans = isPossible ? "YES" : "NO";
		cout << ans << endl;
	}
	return 0;
}