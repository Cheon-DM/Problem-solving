#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

bool prime(string num){
    int n = stoi(num);
    
    if (n < 2) return false;
    int a = (int) sqrt(n);
    for (int i = 2; i <= a; i++){
        if (n % i == 0) return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = -1;
    string num = "";
    stack<int> s;
    int tmp;
    
    while(1){
        if (n == 0) break;
        tmp = n % k;
        n /= k;
        s.push(tmp);
    }
    
    while (!s.empty()){
        tmp = s.top();
        s.pop();
        num += to_string(tmp);
    }
    
    char* result;
    vector<char*> v;
    result = strtok((char*)num.c_str(), "0");
    
    while(result != NULL){
        v.push_back(result);
        result = strtok(NULL, "0");
    }
    
    if (!v.empty()) answer = 0;
    for (int i = 0; i < v.size(); i++){
        bool chk = prime(v[i]);
        if (chk) answer++;
    }
    
    
    return answer;
}