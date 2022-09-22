#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i = 0; i < n; i++){
        string a = "";
        string b = "";
        string tmp = "";
        
        while (arr1[i] != 0){
            a.insert(0, to_string(arr1[i] % 2));
            arr1[i] /= 2;
        }
        
        while (a.length() != n) {
            a.insert(0, "0");
        }
        
        while (arr2[i] != 0){
            b.insert(0, to_string(arr2[i] % 2));
            arr2[i] /= 2;
        }
        
        while(b.length() != n){
            b.insert(0, "0");
        }
        
        for (int j = 0; j < n; j++){
            if (a[j] == '1' || b[j] == '1'){
                tmp.append("#");
            }
            if (a[j] == '0' && b[j] == '0'){
                tmp.append(" ");
            }
        }
        answer.push_back(tmp);
    }
    
    return answer;
}