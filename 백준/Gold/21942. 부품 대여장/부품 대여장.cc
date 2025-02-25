#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#define INF 987654321
#define lld long long

#define MINDAY 1440

using namespace std;

int N, F, DDD, MM, hh, mm, DDDt;
string L, P, M;
int dayInMonth[13] = {0,
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
int dayPassedInMonth[13];
map<pair<string, string>, int> m;
map<string, lld> result;


int stringToInt(string s) {
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		ret *= 10;
		ret += (int)(s[i] - '0');
	}
	return ret;
}

void initL() {
	string s_DDD = L.substr(0, 3);
	string s_hh = L.substr(4, 2);
	string s_mm = L.substr(7, 2);
	DDD = stringToInt(s_DDD);
	hh = stringToInt(s_hh);
	mm = stringToInt(s_mm);
	DDDt = DDD*MINDAY + hh*60 + mm;

	for (int i = 1; i <= 12; i++) {
		dayPassedInMonth[i] = dayPassedInMonth[i-1] + dayInMonth[i-1];
	}
}

int dateToInt(string d, string t) {
	//  1  2  3  4  5  6  7  8  9 10 11 12
	// 31 29 31 30 31 30 31 31 30 31 30 31
	int MM = stringToInt(d.substr(5, 2));
	int dd = stringToInt(d.substr(8, 2));
	int dayPassed = dayPassedInMonth[MM] + dd;
	int hh = stringToInt(t.substr(0, 2));
	int mm = stringToInt(t.substr(3, 2));
	int ret = dayPassed * MINDAY + hh * 60 + mm;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> F;
	initL();
	for (int i = 0; i < N; i++) {
		string d, t;
		cin >> d >> t >> P >> M;
		int time = dateToInt(d, t);
		map<pair<string, string>, int>::iterator iter = m.find({ P, M });
		if (iter != m.end()) { // 반납일 경우
			int bTime = iter->second;
			int diff = time - bTime;
			if (diff > DDDt) { // 반납시간이 지났으면
				if (result.find(M) != result.end()) { // 첫 벌금이 아니면
					result.at(M) += (diff-DDDt) * F;
				}
				else { // 첫 벌금일시
					result.insert({ M, (diff-DDDt)*F });
				} 
			}
			m.erase({ P, M });
		}
		else {
			m.insert({ {P, M}, time });
		}
	}

	for (map<string, lld>::iterator iter = result.begin(); iter != result.end(); iter++) {
		cout << iter->first << ' ' << iter->second << '\n';
	}
	if (result.size() == 0) {
		cout << "-1\n";
	}
	return 0;
}