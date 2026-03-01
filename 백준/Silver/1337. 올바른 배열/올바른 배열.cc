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
백준 
*/
int N;
vector<int> v;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    v = vector<int>(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int max_seq = 1;
    int curr_seq = 1;
    for(int i = 0; i < N; i++) {
        curr_seq = 1;
        for(int j = i+1; j < N; j++) {
            if(v[j] - v[i] < 5) ++curr_seq;
        }
        max_seq = max(max_seq, curr_seq);
    }
    cout << 5 - max_seq;
    return 0;
}