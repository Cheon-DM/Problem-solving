#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    vector<char> t = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    vector<int> score = {0, 0, 0, 0, 0, 0, 0, 0};
    vector<int>::iterator itr;
    int a,b;
    
    for (int i = 0; i < survey.size(); i++){
        for (int j = 0; j < t.size(); j++){
            if (t[j] == survey[i][0]) {
                a = j;
            }

            if (t[j] == survey[i][1]){
                b = j;
            }
        }

        if (choices[i] > 3){
            score[b] += choices[i] - 4;
        }
        else {
            score[a] += 4 - choices[i];
        }
    }

    string answer = "";
    int tmp;
    for (int i = 0; i < 8; i+=2){
        tmp = (score[i] >= score[i+1]) ? i : i+1;
        answer += t[tmp];
    }

    return answer;
}