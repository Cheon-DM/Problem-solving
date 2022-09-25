#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> result;

    map<string, set<string>> list;
    map<string, set<string>>::iterator it;
    
    // 초기화 
    for (int i = 0; i < id_list.size(); i++){
        result[id_list[i]] = 0;
    }
    
    for (int i = 0; i < report.size(); i++){
        vector<string> v; // v[0] = 신고자, v[1] = 신고당한 자
        stringstream ss(report[i]);
        ss.str(report[i]);
        
        string word;
        while(ss >> word){
            v.push_back(word);
        }
        
        it = list.find(v[1]);
        
        if (it != list.end()){ // 신고 당한 자가 list에 있음
            (*it).second.insert(v[0]); // 신고자를 list에 추가
        }
        else { // 신고 당한 자가 list에 없음
            set<string> s;
            s.insert(v[0]);
            list[v[1]] = s;
        }  
    }
    
    for (it = list.begin(); it != list.end(); it++){ // 신고 누적 횟수 저장
        set<string> s = (*it).second;
        set<string>::iterator iter;
        if (s.size() >= k){
            for (iter = s.begin(); iter != s.end(); iter++){
                result[(*iter)] += 1;
            }
        }
        

    }
    
    for (int i = 0; i < id_list.size(); i++){
        answer.push_back(result[id_list[i]]);
    }
    
    return answer;
}