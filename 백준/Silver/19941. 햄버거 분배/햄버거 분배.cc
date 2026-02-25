#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <map>
#include <climits>
#include <set>
#include <string>
#include <string.h>
#include <time.h>
#define INF 987654321
#define lld long long int
#define pii pair<int, int>
#define pdd pair<double, double>
// #define DEBUG
// #define MOD 1000000009

using namespace std;

/*
백준 19941
*/
int N, K;
vector<bool> buggers;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    int cnt = 0;
    cin >> N >> K;
    cin >> str;
    buggers = vector<bool>(N, false);
    for(int i = 0; i < N; i++) {
        if(str[i] == 'P') {
            bool eat = false;
            for(int j = max(i - K, 0); j <= min(N-1, i + K); j++) {
                if(str[j] == 'H' && !buggers[j]) {
                    buggers[j] = true;
                    eat = true;
                    break;
                }
            }
            if(eat) ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
