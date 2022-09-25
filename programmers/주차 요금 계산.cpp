#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

int _Max = 1439;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, vector<int>> car; // 차량번호, (들어온 시간, 총사용시간)
    map<int, vector<int>>::iterator it;
    
    for (int i = 0; i<records.size(); i++){
        vector<string> v;
        stringstream ss(records[i]);
        ss.str(records[i]);
        
        string word;
        while(ss >> word){ // record : 시각(v0), 차량번호(v1), 내역(v2)
            v.push_back(word);
        }
        
        char* result = strtok((char*)v[0].c_str(), ":");
        vector<string> time; // HH:MM
        while(result != NULL){
            time.push_back(result);
            result = strtok(NULL, ":");
        }
        
        int min = stoi(time[0])*60 + stoi(time[1]); // 분 시간

        it = car.find(stoi(v[1]));
        
        if (it != car.end()){ // find
            if (v[2] == "IN"){
                (*it).second[0] = min;
            }
            if (v[2] == "OUT"){
                (*it).second[1] += min - (*it).second[0];
                (*it).second[0] = -1;
            }
        }
        else{ // not find
            vector<int> tmp;
            tmp.push_back(min);
            tmp.push_back(0);
            car.insert(make_pair(stoi(v[1]), tmp));
        }
    }
    
    for (it = car.begin(); it != car.end(); it++){
        if ((*it).second[0] != -1){ // in
            (*it).second[1] += (_Max - (*it).second[0]);
            (*it).second[0] = -1;
        }
    }
    
    map<int, vector<int>>::iterator it2;
    for (it2 = car.begin(); it2 != car.end(); it2++){
        if (fees[0] > (*it2).second[1]) answer.push_back(fees[1]);
        
        else {
            float tmp = (*it2).second[1] - fees[0];
            answer.push_back(fees[1] + (ceil(tmp / fees[2]) * fees[3]));
        }
    }
    
    return answer;
}