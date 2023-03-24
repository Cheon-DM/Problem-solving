#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (const pair<int, int> &a, const pair<int, int> &b){
    if (a.second == b.second){
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main(){
    
    int meeting;
    cin >> meeting;

    vector<pair<int, int>> list;
    for (int i = 0 ; i < meeting; i++){
        int a, b;
        cin >> a >> b;
        list.push_back(make_pair(a,b));
    }
    
    // 종료시간이 빠른 순
    sort(list.begin(), list.end(), compare);

    int time = list[0].second;
    int max = 1;
    for( int i = 1; i < meeting; i++){
        if (time <= list[i].first){
            time = list[i].second;
            max++;
        }
    }

    cout << max;
    return 0;

}