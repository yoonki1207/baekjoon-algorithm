#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, ans;
int arr[102][72];
int brr[102][72];
int offset[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}};

bool isTop(int y, int x) {
    int h = arr[y][x];
    for(int i = 0; i < 8; i++) {
        int offsetY = y + offset[i][0];
        int offsetX = x + offset[i][1];
        if(arr[offsetY][offsetX] > h) {
            return false;
        }
    }
    return true;
}

void makeMountainAsH(int y, int x, int h) {
    if(!isTop(y, x) || brr[y][x]) return;
    int trr[102][72] = {0};
    queue<pair<int, int>> q;
    q.push({y, x});
    trr[y][x] = 1;
    while(!q.empty()) {
        pair<int, int> coord = q.front();
        q.pop();
        for(int i = 0; i < 8; i++) {
            int offsetY = coord.first + offset[i][0];
            int offsetX = coord.second + offset[i][1];
            // if(y == 1 && x == 2) {
            //     printf("Info: [%d], [%d] > %d", offsetY, offsetX, arr[offsetY][offsetX]);
            // }
            if(arr[offsetY][offsetX] > h) {
                // cout  << "ERROR from: " << y << ", " << x << " :" << offsetY << " " << offsetX << endl;
                return;
            }
            if(arr[offsetY][offsetX] == h && trr[offsetY][offsetX] == 0) {
                q.push({offsetY, offsetX});
                trr[offsetY][offsetX] = 1;
            }
        }
    }
    // cout << "Do from " << y << " " << x << endl;
    ans++;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(trr[i][j]) brr[i][j] = 1;
            // cout << trr[i][j] << ' ';
        }
        // cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <=m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            makeMountainAsH(i, j, arr[i][j]);
        }
    }
    bool isSameAll = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(arr[i][j] != arr[1][1]) {
                isSameAll = false;
                break;
            }
        }
    }
    if(isSameAll) cout << 0;
    else cout << ans;
    
    return 0;
}