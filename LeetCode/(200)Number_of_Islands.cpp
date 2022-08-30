/* bfs */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 0) return 0;

        int cnt = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    checking(grid, i, j);
                }
            }
        }

        return cnt;
    }

    void checking(vector<vector<char>>& grid, int x, int y){
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;

        if (grid[x][y] == '0') return;

        grid[x][y] = '0';
        checking(grid, x-1, y);
        checking(grid, x+1, y);
        checking(grid, x, y-1);
        checking(grid, x, y+1);
    }
};