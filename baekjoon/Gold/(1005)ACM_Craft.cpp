#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;

int main(){
    fio;
    int t, n, k, w;
    cin >> t; // t = testcase 수

    for (int a = 0; a < t; a++){
        int indegree[1001] = {0, };
        int buildTime[1001] = {0, };
        vector<int> order[1001]; // order = 건설 순서
        queue <int> route;
        /**
         * input
        */
        cin >> n >> k; // n = 건물의 개수, k = 건물 간의 건설순서 규칙 개수
        int d[n + 1];  // d = 건물 건설 시간
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
        }
        
        int x, y;                // x -> y : 건설 순서
        for (int i = 1; i <= k; i++) {
            cin >> x >> y;
            order[x].push_back(y); // x에 대한 다음 건설 건물 y list
            indegree[y]++;
        }
        cin >> w; // w = 건설 번호
        
        /**
         * solution
        */

        for (int i = 1; i <= n ; i++){
            if (indegree[i] == 0){
                route.push(i);
                buildTime[i] = d[i];
            }
        }    

        while (route.empty() == 0){
            int current = route.front();
            route.pop();

            for (int i = 0; i < order[current].size(); i++){
                int next = order[current][i];
                buildTime[next] = max(buildTime[next], buildTime[current] + d[next]);
                indegree[next]--;

                if (indegree[next] == 0){
                    route.push(next);
                }
            }

            
        }

        cout << buildTime[w] << "\n";
    }
    
}