#include <string>
#include <vector>

using namespace std;

inline int get_height(int n, int w) {
    return (n + w - 1) / w; // starts with 1
}

inline bool get_rl(int height) {
    return !(height % 2);
}

inline int get_x(int n, int w) {
    bool isRL = get_rl(get_height(n, w));
    int x_offset = (n - 1) % w;
    return isRL ? w - x_offset - 1 : x_offset;
}

int solve(int n, int w, int num) {
    int answer = 0;
    int x = get_x(num, w);
    int y = get_height(num, w);
    
    int max_height = get_height(n, w);
    bool maxRL = get_rl(max_height);
    
    if(max_height == y) return 1;
    
    bool is_max = false;
    if(maxRL) {
        if(x + (n % w) >= w) is_max = true;
    } else {
        if(x + 1 <= (n % w)) is_max = true;
    }
    if(n % w == 0) is_max = true;
    if(is_max) answer = max_height - y;
    else answer = max_height - y - 1;
    return answer + 1;
}

int solution(int n, int w, int num) {
    vector<vector<int>> v(100, vector<int>(100, 0));
    int x = 0, y = 0, d = 0;
    for(int val = 1; val <= n; val++) {
        v[y][x] = val;
        if(val % w == 0 || (x == 0 && d)) {
            d = !d;
            y++;
        } else {
            if(d == 0) x++;
            else x--;   
        }
    }
    return solve(n, w, num);
}