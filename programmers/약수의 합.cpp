#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt = 1;
    while(n >= cnt){
        if (n % cnt == 0){
            answer += cnt;
        }
        cnt++;
    }
    
    return answer;
}