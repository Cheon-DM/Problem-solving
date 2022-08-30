/* backtracking */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n, m; // n*n 도시, m개의 치킨집
int city[52][52] = {0, };
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
pair<int, int> pickChicken[16];
int minTotal = 1000000;

void backtracking(int num, int tmp){
    if (num == m){
        int total = 0;
        for (int i = 0; i < house.size(); i++){
            int distance;
            int minDis = 100000000;
            for (int j = 0; j < m; j++){
                distance = abs(house[i].first - pickChicken[j].first) + abs(house[i].second - pickChicken[j].second);
                minDis = min(minDis, distance);
            }
            total += minDis;
        }
        if (minTotal > total) minTotal = total;
        return;
    }

    for (int i = tmp; i < chicken.size(); i++){
        pickChicken[num] = chicken[i];
        backtracking(num + 1, i + 1);
    }
}

int main(){
    fio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> city[i][j];
            if (city[i][j] == 1) house.push_back(make_pair(i, j));
            if (city[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }

    backtracking(0, 0);
    cout << minTotal;

    return 0;
}