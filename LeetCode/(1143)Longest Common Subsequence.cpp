/**
 * leetcode - 1143
 * string, DP
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<short>> v;
        v.assign(text1.size()+1, vector<short>(text2.size()+1, 0));
        for (int i = 0; i < text1.size(); i++){
            for (int j = 0; j < text2.size(); j++){
                if (text1[i] == text2[j]){
                    v[i+1][j+1] = v[i][j] + 1;
                }
                else {
                    v[i+1][j+1] = max(v[i+1][j], v[i][j+1]);
                }
            }
        }

        return v[text1.size()][text2.size()];
    }
};