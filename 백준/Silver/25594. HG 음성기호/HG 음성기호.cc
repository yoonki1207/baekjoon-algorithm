#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define INF 987654321
#define lld long long

using namespace std;

string hg[255];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	hg['a'] = "aespa";	
	hg['b'] = "baekjoon";	
	hg['c'] = "cau";	
	hg['d'] = "debug";	
	hg['e'] = "edge";	
	hg['f'] = "firefox";	
	hg['g'] = "golang";	
	hg['h'] = "haegang";	
	hg['i'] = "iu";	
	hg['j'] = "java";	
	hg['k'] = "kotlin";	
	hg['l'] = "lol";	
	hg['m'] = "mips";	
	hg['n'] = "null";	
	hg['o'] = "os";	
	hg['p'] = "python";	
	hg['q'] = "query";	
	hg['r'] = "roka";	
	hg['s'] = "solvedac";	
	hg['t'] = "tod";	
	hg['u'] = "unix";	
	hg['v'] = "virus";	
	hg['w'] = "whale";	
	hg['x'] = "xcode";	
	hg['y'] = "yahoo";	
	hg['z'] = "zebra";	
	string s;
	cin >> s;
	vector<char> cs;
	bool isHG = true;
	for(int i = 0; i < s.size();) {
		string cmp = hg[s[i]];
		if(cmp.compare(s.substr(i, cmp.size())) == 0) {
			cs.push_back(s[i]);
			i += cmp.size();
		} else {
			isHG = false;
			break;
		}
	}

	if(isHG) {
		cout << "It's HG!\n";
		for(auto c: cs) cout << c;
		cout << '\n';
	} else {
		cout << "ERROR!";
	}
	return 0;
}