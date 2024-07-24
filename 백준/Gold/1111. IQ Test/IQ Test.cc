#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int a0, a1, b;
bool isValid = true;

void makeFunc(int v0, int v1, int v2) {
    a1 = v2 - v1;
    if(a1 != 0) {
        a0 = v1 - v0;
    } else {
        a0 = 1;
    }
    if(a0 == 0 || (double)a1/a0 != (double)((int)(a1/a0))) {
        isValid = false;
        return;
    }
    double bb = v1 - v0 * a1 / a0;
    b = bb;
}

void isValidFunction(const vector<int>& v) {
    if(isValid == false) return;
    for(int i = 0; isValid &&  i < v.size() - 1; i++) {
        int next = v[i]*a1/a0 + b;
        if(next != v[i+1]) {
            isValid = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; v.push_back(x);
    }
    if(n <= 2) {
        if(n == 2 && v[0] == v[1]) {
            cout << v[0];
        } else {
            cout << 'A'; // TODO: if n == 2 && v[0]
        }
        
    } else {
        makeFunc(v[0], v[1], v[2]);
        isValidFunction(v);
        if(isValid) {
            int next = v[n-1] * a1 / a0 + b;
            cout << next;
        } else {
            cout << 'B';
        }
    }
    return 0;
}