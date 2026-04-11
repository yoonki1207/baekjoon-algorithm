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
#include <random>
#include <stdio.h>
#include <stdlib.h>
#define INF 987654321
#define lld long long int
#define pii pair<int, int>
#define pdd pair<double, double>
// #define DEBUG
// #define MOD 1000000009

using namespace std;

int N, diff_cnt, ans, ss;
string s;
int arr[CHAR_MAX] = {0};
int brr[CHAR_MAX] = {0};

int main(int argc, char *argv[]) { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> s;
    ss = s.size();
    for(int i = 0; i < s.size(); i++) {
        arr[(int)s[i]]++;
    }
    for(int i = 0; i < N-1; i++) {
        cin >> s;
        memset(brr, 0, sizeof(brr));
        for(int j = 0; j < s.size(); j++) {
            brr[(int)s[j]]++;
        }

        diff_cnt = 0;
        int cnt = 0;
        for(int j = 0; j < CHAR_MAX; j++) {
            diff_cnt += abs(arr[j] - brr[j]);
            if(arr[j] && brr[j]) {
                cnt+= min(arr[j], brr[j]);
            }
        }
        
        if(diff_cnt <= 1 || (cnt == ss - 1 && s.size() == ss)) {
            ans++;
        }
        // cout << s << ": " << diff_cnt << ", " << cnt << endl;
    }
    cout << ans;  
    return 0;
}