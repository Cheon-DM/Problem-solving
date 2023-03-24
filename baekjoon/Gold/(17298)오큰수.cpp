/**
 * baekjoon - 17298
 * stack
 */

#include <iostream>
#include <stack>
#include <vector>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main(){
    fio;
    //input
    int n, x;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
    }

    //sol
    stack<int> s;
    vector<int> result(n);
    for (int i = n - 1; i >= 0; i--){
        while (!s.empty() && s.top() <= a[i]){
            s.pop();
        }

        if (s.empty()) result[i] = -1;
        else result[i] = s.top();

        s.push(a[i]);
    }

    for (int i = 0; i < n; i++){
        cout << result[i] <<" ";
    }


    return 0;
}