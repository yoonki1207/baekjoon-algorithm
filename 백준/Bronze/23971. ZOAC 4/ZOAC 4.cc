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
#define lld long long

using namespace std;

int H, W, N, M;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> H >> W >> N >> M;
	int answer = ceil((double)H / (N + 1)) * ceil((double)W / (M + 1));
	cout << answer;
	return 0;
}
