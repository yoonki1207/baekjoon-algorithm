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
백준 17484

*/
constexpr int NR[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int DIR[127];
int N, K;
string command;
/*
A: 차가 일정한 것 중에서 x가 더 큰 것 중 가장 작은 것
B: 합이 일정한 것 중에서 x가 더 큰 것 중 가장 작은 것
C: 차가 일정한 것 중에서 x가 더 작은 것 중 가장 큰 것
D: 합이 일정한 것 중에서 x가 더 작은 것 중 가장 큰 것

X - Y의 모든 가짓수는 최대 N개.
X + Y의 모든 가짓수는 최대 N개.
차가 일정한 배열 diff_arr을 만들고, 각 차에 대해서 부합하는 배열을 매핑한다.
즉, vector<pair<int, vector<int>>> diff_arr을 선언한 후 first에는 차, vector<int>에는 좌표를 설정한다.
X + Y에 대해서도 같은 맥락의 배열 add_arr을 선언한다.
입력받은 coordinates에 대해서 diff_arr과 add_arr을 초기화한다.

.. 정답 확인
미리 그래프를 연결해놓는다.
좌표 이동을 그래프라고 변환하여 생각하는 것이 핵심인 문제다.
식물이 제거된다는 것은 다른 노드와 연결해주면 된다.

좌표 구조체를 만든다.
합이 일정한 것 끼리 정렬하여 연결한다.
차가 일정한 것 끼리 정렬하여 연결한다.
*/
typedef struct Node {
    int x, y;
    int diff, sum;
    Node *A, *B, *C, *D;
} Node;
vector<Node*> coords;

void removeNode(Node* node) {
    if(node->D) node->D->A = node->A;
    if(node->A) node->A->D = node->D;
    if(node->B) node->B->C = node->C;
    if(node->C) node->C->B = node->B;
}


int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    DIR['A'] = 0; DIR['B'] = 1; DIR['C'] = 2; DIR['D'] = 3;
    cin >> N >> K;
    cin >> command;
    int x, y;
    coords = vector<Node*>(N);
    for(int i = 0; i < N; i++) coords[i] = new Node();
    set<int> diff_set, sum_set;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        coords[i]->x = x;
        coords[i]->y = y;
        coords[i]->diff = x - y;
        diff_set.insert(x - y);
        coords[i]->sum = x + y;
        sum_set.insert(x + y);
    }
    vector<int> diff_i(diff_set.begin(), diff_set.end());
    vector<int> sum_i(sum_set.begin(), sum_set.end());
    sort(diff_i.begin(), diff_i.end());
    sort(sum_i.begin(), sum_i.end());
    vector<vector<Node*>> diff_v(diff_i.size());
    vector<vector<Node*>> sum_v(sum_i.size());
    for(int i = 0; i < N; i++) {
        Node* node = coords[i];
        auto iter1 = lower_bound(diff_i.begin(), diff_i.end(), node->diff);
        diff_v[iter1 - diff_i.begin()].push_back(node);
        auto iter2 = lower_bound(sum_i.begin(), sum_i.end(), node->sum);
        sum_v[iter2 - sum_i.begin()].push_back(node);
    }
    for(auto& arr: diff_v) {
        sort(arr.begin(), arr.end(), [](const Node* a, const Node* b) {
            return a->x < b->x;
        });
        if(arr.size() >= 2) {
            arr[0]->A = arr[1];
            for(int i = 1; i < arr.size() - 1; i++) {
                arr[i]->A = arr[i+1];
                arr[i]->D = arr[i-1];
            }
            arr[arr.size()-1]->D = arr[arr.size() - 2];
        }
    }
    for(auto& arr: sum_v) {
        sort(arr.begin(), arr.end(), [](const Node* a, const Node* b) {
            return a->x < b->x;
        });
        if(arr.size() >= 2) {
            arr[0]->B = arr[1];
            for(int i = 1; i < arr.size() - 1; i++) {
                arr[i]->B = arr[i+1];
                arr[i]->C = arr[i-1];
            }
            arr[arr.size()-1]->C = arr[arr.size() - 2];
        }
    }
    Node* node = coords[0];
    for(int i = 0; i < K; i++) {
        // cout << command[i] << endl;
        Node* prev = node;
        if(command[i] == 'A') {
            if(node->A) {
                node = node->A;
                removeNode(prev);
            }
        } else if(command[i] == 'B') {
            if(node->B) {
                node = node->B;
                removeNode(prev);
            }
        } else if(command[i] == 'C') {
            if(node->C) {
                node = node->C;
                removeNode(prev);
            }
        } else {
            if(node->D) {
                node = node->D;
                removeNode(prev);
            }
        }
        
    }
    cout << node->x << ' ' << node->y << endl;
    
    return 0;
}
