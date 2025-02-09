#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#define INF 987654321

using namespace std;

int arr[100001];
unordered_map<int, bool> umap;

bool isPresent(int x) {
    return umap.find(x) != umap.end();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 100000;
    cin >> n;
    arr[0] = 0;
    umap.insert({0, true});
    unordered_map<int, bool>::iterator iter = umap.find(1);

    for(int i = 1; i <= n; i++) {
        arr[i] = arr[i-1] - i;
        if(isPresent(arr[i]) || arr[i] < 0) {
            arr[i] = arr[i-1] + i;
        }
        umap.insert({arr[i], true});
    }
    cout << arr[n] << endl;
    return 0;
}