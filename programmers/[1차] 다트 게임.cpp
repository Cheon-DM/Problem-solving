#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score[3] = {0, };
    int cnt = 0;
    string tmp = "";
    for (int i = 0; i < dartResult.length(); i++){
        // 정수
        if (dartResult[i] >= '0' && dartResult[i] <= '9'){
            tmp += dartResult[i];
            continue;
        }
        
        // S
        if (dartResult[i] == 'S'){
            score[cnt] += stoi(tmp);
            cnt++;
            tmp = "";
            continue;
        }
        
        // D
        if (dartResult[i] == 'D'){
            score[cnt] += stoi(tmp) * stoi(tmp);
            cnt++;
            tmp = "";
            continue;
        }
        
        // T
        if (dartResult[i] == 'T'){
            score[cnt] += stoi(tmp) * stoi(tmp) * stoi(tmp);
            cnt++;
            tmp = "";
            continue;
        }
        
        // 스타상
        if (dartResult[i] == '*'){
            score[cnt-1] *= 2;
            if (cnt != 1){
                score[cnt-2] *= 2;
            }
        }
        
        // 아차상
        if (dartResult[i] == '#'){
            score[cnt-1] *= -1;
        }
        
    }
    answer = score[0] + score[1] + score[2];
    return answer;
}