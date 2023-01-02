/**
 * baekjoon - 1339
 * greedy
*/

#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
string s;
vector<string> words;
map<string, int> m;

bool cmp(pair<string, int> a, pair<string, int> b){
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

void Input(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> s;
        words.push_back(s);
    }
}

void Solution(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < words[i].size(); j++){
            string word = words[i].substr(j, 1);
            m[word] += int(pow(10, words[i].size()-j-1));
        }
        
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);

    int answer = 0;
    int index = 9;
    for (auto alpha: v){
        answer += index-- * alpha.second;
    }

    cout << answer;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Solution();
}