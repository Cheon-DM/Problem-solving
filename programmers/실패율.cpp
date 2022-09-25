#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b){
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> ratio;
    vector<double> fail(N+2, 0);
    int total = stages.size();
    
    for (int i = 0; i < stages.size(); i++){
        fail[stages[i]]++;
    }
    
    double minus_member = 0;
    
    for (int i = 1; i <= N; i++){
        if (fail[i] == 0) {
            ratio.push_back({i, 0});
            continue;
        }
        ratio.push_back({i, fail[i] / (total - minus_member)});
        minus_member += fail[i];
    }
    
    sort(ratio.begin(), ratio.end(), compare);
    
    for (auto a: ratio){
        answer.push_back(a.first);
    }
    
    return answer;
}