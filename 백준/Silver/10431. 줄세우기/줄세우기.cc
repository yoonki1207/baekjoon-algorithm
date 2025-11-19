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
#define MAX_N 32001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG
#define MOD 1000000009

using namespace std;

int T;
int arr[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    int test_case;
    for(int _t = 0; _t < T; _t++) {
        cin >> test_case;
        vector<int> v;
        int x;
        int cnt = 0;
        for(int i = 0; i < 20; i++) {
            cin >> x;
            v.push_back(x);
            int index = v.size() - 1;
            while(index - 1 >= 0 && v[index] < v[index-1]) {
                swap(v[index], v[index-1]);
                index--;
                cnt++;
            }
        }
        arr[test_case] = cnt;
    }
    for(int i = 1; i <= T; i++) {
        cout << i << ' ' << arr[i] << '\n';
    }
    return 0;
}
