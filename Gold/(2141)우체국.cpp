#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<pair<long, long>> v1;
    int x, y;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v1.push_back(make_pair(x,y));
        sum += y;
    }

    sort(v1.begin(), v1.end());

    long long chk = 0;

    for (int i = 0; i < n; i++){
        chk += v1[i].second;
        if (chk >= ((sum+1)/2)){
            cout << v1[i].first;
            break;
        }
    }
}