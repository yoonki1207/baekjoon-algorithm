#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define INF 987654321

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    string gs;
    string cs;
    cin >> gs >> cs;
    sort(gs.begin(), gs.end()); sort(cs.begin(), cs.end(), greater<char>());
    int n = gs.size();
    vector<char> v(n);
    int i = 0, j = (n+1)/2 - 1;
    int p = 0, q = n/2 - 1;
    int left = 0, right = n-1;
    for(int turn = 0; turn < n; turn++) {
        if(turn % 2 == 0) {
            if(p <= q && gs[i] >= cs[p]) {
                v[right--] = gs[j--];
            } else {
                v[left++] = gs[i++];
            }
        } else {
            if(i <= j && gs[i] >= cs[p]) {
                v[right--] = cs[q--];
            } else {
                v[left++] = cs[p++];
            }
        }
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    return 0;
}

/*

bb
aa
ab

bbbb
aaaa
abba

33
41
34

222
111
212
122/
12


456
321
453 
345/
35

5678
4321
4356

3456/??5?
6453/?45?
3456/?456

구사과와 큐브러버가 게임을 한다
구사과가 먼저 시작한다.

N이 짝수라면, 큐브러버가 마지막에 수를 둔다.
첫 번째 문자는 큐브러버가 둔다.

N이 홀수라면, 구사과가 마지막에 수를 둔다.
첫 번째 문자는 구사과가 둔다.

각 플레이어는 서로의 수를 강제하거나 빼앗는다.

예를 들어, 
222
111
이 존재한다면, 다음이 정답이다.
212

abcdefghijklmnopqrstuvwxyz

본인이 가진 카드가 상대의 어떤 수 보다도 작더라면...
         

*/