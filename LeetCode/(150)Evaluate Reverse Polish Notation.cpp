/**
* leetcode - 150
* array, math, stack
*/

class Solution {
public:
    stack<long long> s;
    long long fir, sec;

    long long evalRPN(vector<string>& tokens) {
        for (int i = 0; i < tokens.size(); i++){
            if (tokens[i] == "+"){
                fir = s.top();
                s.pop();
                sec = s.top();
                s.pop();
                s.push(fir+sec);
            }
            else if (tokens[i] == "-"){
                fir = s.top();
                s.pop();
                sec = s.top();
                s.pop();
                s.push(sec-fir);
            }
            else if (tokens[i] == "*"){
                fir = s.top();
                s.pop();
                sec = s.top();
                s.pop();
                s.push(sec*fir);
            }
            else if (tokens[i] == "/"){
                fir = s.top();
                s.pop();
                sec = s.top();
                s.pop();
                s.push(sec/fir);
            }
            else{
                s.push(stol(tokens[i]));
            }            
        }

        return s.top();
    }
};