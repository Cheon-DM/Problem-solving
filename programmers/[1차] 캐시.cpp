#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache(cacheSize + 1, "");
    int tmpIndex = -1;
    int chk = 0;
    string tmpCity = "";
    
    //tolower
    for (int i = 0; i < cities.size(); i++){
        for (int j = 0; j < cities[i].length(); j++){
            cities[i][j] = tolower(cities[i][j]);  
        }
    }
    
    // cacheSize = 0
    if (cacheSize == 0) return 5 * cities.size();
  
    for (int i = 0; i < cities.size(); i++){        
        for (int j = 0; j < cacheSize; j++){            
            if (cache[j] == cities[i]){ // find cache
                answer++;
                tmpIndex = j;
                tmpCity = cache[j];
                break;
            }            
            
            else if (cache[j] == ""){ // cache not full
                answer += 5;
                cache[j] = cities[i];
                tmpIndex = -1;
                chk++;
                break;
            }
            
            else if (j == cacheSize-1){ // not find cache
                answer += 5;
                tmpIndex = 0;
                tmpCity = cities[i];
                break;
            }
        }
        
        // pulling cities
        for (int j = tmpIndex; j < cacheSize-1; j++){
            if (tmpIndex == -1) break;
            cache[j] = cache[j+1];
        }
        
        if (tmpIndex != -1){
            cache[chk-1] = tmpCity;
        }
    }
    return answer;
}