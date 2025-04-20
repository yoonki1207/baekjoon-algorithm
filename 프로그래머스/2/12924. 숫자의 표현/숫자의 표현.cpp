#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= n; i++) {
        double j = (double)(2*n-i*(i-1))/(double)(2*i);
        int jj = (int)j;
        if(j >= 1 && (double)jj == j) {
            answer++;
        }
    }
    
    return answer;
}