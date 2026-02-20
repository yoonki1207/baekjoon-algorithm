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
백준 

*/
int P, M;
vector<pair<int, string>> players;

void printRooms(const vector<int>& room) {
    vector<pair<string ,int>> tmp;
    for(auto idx: room) {
        // cout << players[idx].first << ' ' << players[idx].second << '\n';    
        tmp.push_back({players[idx].second, players[idx].first});
    }
    sort(tmp.begin(), tmp.end());
    for(auto t: tmp) {
        cout << t.second << ' ' << t.first << '\n';
    }
}

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> P >> M;
    players = vector<pair<int, string>>(P);
    for(int i = 0; i < P; i++) {
        cin >> players[i].first >> players[i].second;
    }
    vector<bool> visited(P);
    vector<vector<int>> rooms;
    // 1. if no room, then create a room
    // 2. if there is a room that can enter, then enter.
    // 3. if there is two or more room that can enter, then enter the room created earlier.
    while(true) {
        bool allVisited = true;
        for(int i = 0; i < P; i++) {
            if(visited[i]) continue;
            visited[i] = true;
            allVisited = false;
            pair<int, string>& player = players[i];
            
            // search room
            bool found = false;
            for(int j = 0; j < rooms.size(); j++) {
                if(rooms[j].size() == M) continue;
                const pair<int, string>& host = players[rooms[j][0]];
                if(host.first + 10 >= player.first && host.first - 10 <= player.first) {
                    found = true;
                    rooms[j].push_back(i);
                    break;
                }
            }
            if(!found) {
                vector<int> tmp;
                tmp.push_back(i);
                rooms.push_back(tmp);
            }
            
        }
        if(allVisited) break;
    }
    for(int i = 0; i < rooms.size(); i++) {
        if(rooms[i].size() == M) {
            cout << "Started!\n";
            printRooms(rooms[i]);
        } else {
            cout << "Waiting!\n";
            printRooms(rooms[i]);
        }
    }

    return 0;
}
