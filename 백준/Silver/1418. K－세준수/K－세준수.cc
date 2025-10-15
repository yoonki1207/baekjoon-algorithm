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
#define INF 987654321
#define MAX_N 32001
#define lld long long int
#define pii pair<int, int>
// #define DEBUG

using namespace std;

int N, k;
bool isPrime[100001];
vector<int> primes;

void init() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for(int n = 2; n <= 100000; n++) {
        if(isPrime[n]) {
            primes.push_back(n);
            for(int i = n*2; i <= 100000; i+=n) {
                isPrime[i] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    init();
    cin >> N >> k;
    vector<int> v(N+1, 1);
    for(int i = 0; i < primes.size(); i++) {
        int n = primes[i];
        while(n <= N) {
            v[n] = max(v[n], primes[i]);
            n += primes[i];
        }
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(v[i] <= k) cnt++;
    }
    cout << cnt;
    return 0;
}