#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int curr_server = 0;
    int arr[26] = {0};
    for(int i = 0; i < players.size(); i++) {
        int needed_server = players[i] / m;
        if(needed_server > curr_server) {
            int additional_server = needed_server - curr_server;
            arr[k] += additional_server;
            answer += additional_server;
            curr_server += additional_server;
        }
        
        curr_server -= arr[1];
        for(int j = 1; j <= 24; j++) {
            arr[j] = arr[j+1];
        }
    }
    return answer;
}