/**
 * programmers - 보석 쇼핑
 * two pointer
*/

#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map<string, int> m;
    
    set<string> s(gems.begin(), gems.end());
    int gemKind = s.size();

    int start, end;
    start = end = 0;
    
    int dist = gems.size()+1;    
    
    while (1){
        // 모든 보석 선택 O
        if (m.size() == gemKind){
            if (dist > end - start){
                dist = end - start;
                answer[1] = end;
                answer[0] = start+1;
            }
            
            if (m[gems[start]] == 1){
                m.erase(gems[start]);
            }
            else {
                m[gems[start]]--;
            }
            start++;
        }
        
        else if (end == gems.size()) break;
        
        // 모든 보석 선택 X
        else {
            m[gems[end++]]++;
        }
    }
    
    return answer;
}