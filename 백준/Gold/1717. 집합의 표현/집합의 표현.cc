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
백준 1717
*/
constexpr int MAX_N = 1'000'001;
int N, M;
int arr[MAX_N];

int getParent(int x) {
    if(x != arr[x]) return arr[x] = getParent(arr[x]);
    return x;
}

void unionParent(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);
    if(pa > pb) swap(pa, pb);
    if(pa != pb) arr[pb] = pa;
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int a, b, c;
    for(int i = 0; i <= N; i++) arr[i] = i;
    for(int i = 0; i < M; i++) {
        cin >> c >> a >> b;
        if(c == 0) {
            unionParent(a, b);
        } else {
            string msg = getParent(a) == getParent(b) ? "YES" : "NO";
            cout << msg << '\n';
        }
    }
    
    return 0;
}