/**
 * baekjoon - 1874
 * stack
 */

#include <iostream>
#include <vector>
#include <stack>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main(){
    fio;
    //input
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    //sol
    vector<string> result;
    stack<int> s;
    s.push(1);
    result.push_back("+");
    bool flag = false;
    int num = 2;
    int index = 0;
    
    while(num <= n || !s.empty()){
        if (s.empty()) {
            s.push(num++);
            result.push_back("+");
            continue;
        }

        int top = s.top();

        if (top < v[index]){
            s.push(num++);
            result.push_back("+");
        }
        
        else if (top == v[index]) {
            s.pop();
            result.push_back("-");
            index++;
        }

        else if (top > v[index]){
            cout << "NO";
            flag = true;
            break;
        }
    }

    if (!flag){
        for (int i = 0; i < result.size(); i++){
            cout << result[i] <<"\n";
        }
    }

    return 0;
}