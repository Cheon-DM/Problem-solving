/**
 * leetcode - 1847
 * array, binary search, sorting
*/

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if (a[1] == b[1]) return a[0] < b[0];
        else return a[1] < b[1];
    }

    int binarySearch(vector<vector<int>>& rooms, int minSize){
        int l = 0;
        int h = rooms.size()-1;
        int ans = -1;

        while (l <= h){
            int m = l + (h-l)/2;

            if (rooms[m][1] < minSize){ // minSize보다 작은 경우 -> 고려X
                l = m+1;
            }
            else { // minSize보다 큰 경우
                ans = m;
                h = m-1;
            }            
        }
        return ans;
    }

    int finding(vector<vector<int>>& rooms, int pre, int start){
        int ans = start;
        int m = abs(rooms[start][0] - pre);

        for (int i = start+1; i < rooms.size(); i++){
            int diff = abs(rooms[i][0] - pre);

            if (diff < m){
                m = diff;
                ans = i;
            }
            else if (diff == m){
                if (rooms[i][0] < rooms[ans][0]){
                    ans = i;
                }
            }
        }

        return ans;
    }

    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        vector<int> answer(queries.size());
        sort(rooms.begin(), rooms.end(), cmp);
        for (int k = 0; k < queries.size(); k++){
            int pre = queries[k][0];
            int size = queries[k][1];
            
            int tmp = binarySearch(rooms, size);
            if (tmp == -1) {
                answer[k] = -1;
                continue;
            }

            int idx = finding(rooms, pre, tmp);
            answer[k] = rooms[idx][0];
        }

        return answer;
    }
};