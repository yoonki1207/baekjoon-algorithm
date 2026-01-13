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
// #define DEBUG
// #define MOD 1000000009

using namespace std;

/*
백준 11812 K진 트리 19:45

mathmetics

둘 중 깊이가 더 깊은 노드의 조상 노드와 남은 노드를 비교하며 올라가기.

노드의 depth = sigma()
*/
int N, D, P;
vector<pair<int, int>> v;
vector<bool> p;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    v = vector<pair<int, int>>(N);
    p = vector<bool>(N, false);
    for(int i = 0; i < N; i++) {
        cin >> D >> P;
        v[i] = {D, P};
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int sales = 0;
    for(int i = 0; i < N; i++) {
        int index = v[i].second - 1;
        int value = v[i].first;
        while(index >= 0 && p[index] == true) --index;
        if(index >= 0 && p[index] == false) {
            p[index] = true;
            sales += value;
        }
    }
    cout << sales;
    
    return 0;
}