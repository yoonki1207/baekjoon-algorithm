// 11723 집합
#include <iostream>
#include <math.h>
#include <string>

int main() {
	int M, count = 0;
	std::cin >> M;
	while (M-- > 0) {
		bool isCountable = true;
		int alpha[26] = { 0 };
		std::string str;
		std::cin >> str;
		alpha[str[0]-'a'] = 1;
		for (int i = 1; i < str.size(); i++) {
			if (str[i] != str[i - 1]) alpha[str[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (alpha[i] > 1)isCountable = false;
		}
		if (str.size() == 1) count++;
		else if (isCountable) count++;
	}
	std::cout << count;
}