#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <string.h>
#define INF 987654321
#define MAX_N 101
#define lld long long
#define pii pair<int, int>

using namespace std;


/*
백준 129886 돌 그룹
DP 문제인듯

500 * 500 * 500 = 
*/

int A, B, C;
bool visited[500][1500];

class Node {
public:
    int a, b, c;
    Node(int a, int b, int c) : a(a), b(b), c(c) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> A >> B >> C;
    queue<Node> q;
    vector<int> tmpV{ A, B, C };
    sort(tmpV.begin(), tmpV.end());
    visited[tmpV[0]][tmpV[2]] = true;
    q.push({ tmpV[0], tmpV[1], tmpV[2]});
    //visited[1][2][7] = true;
    bool ans = false;
    if ((A + B + C) % 3 != 0) {
        cout << 0; return 0;
    }
    while (!q.empty() && ans == false) {
        Node front = q.front();
        q.pop();
        //cout << front.a << ' ' << front.b << ' ' << front.c << endl;
        if (front.a == front.b && front.b == front.c) {
            ans = true;
            break;
        }
        int X, Y;
        vector<int> v(3);
        if (front.a != front.b) {
            X = min(front.a, front.b);
            Y = max(front.a, front.b);
            //vector<int> v{ X*2, Y-X, front.c };
            v[0] = X * 2; v[1] = Y - X; v[2] = front.c;
            sort(v.begin(), v.end());
            if (!visited[v[0]][v[2]]) {
                visited[v[0]][v[2]] = true;
                q.push({ v[0], v[1], v[2] });
            }
        }
        if (front.a != front.c) {
            X = min(front.a, front.c);
            Y = max(front.a, front.c);
            v[0] = X * 2; v[1] = Y - X; v[2] = front.b;
            sort(v.begin(), v.end());
            if (!visited[v[0]][v[2]]) {
                visited[v[0]][v[2]] = true;
                q.push({ v[0], v[1], v[2] });
            }
            
        }
        if (front.b != front.c) {
            X = min(front.b, front.c);
            Y = max(front.b, front.c);
            v[0] = X * 2; v[1] = Y - X; v[2] = front.a;
            sort(v.begin(), v.end());
            if (!visited[v[0]][v[2]]) {
                visited[v[0]][v[2]] = true;
                q.push({ v[0], v[1], v[2] });
            }
        }
    }
    cout << ans;
    return 0;
}