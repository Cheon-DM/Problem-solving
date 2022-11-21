/**
 * Leetcode - 257
 * string, backtracking, tree, dfs, binary tree
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};


class Solution {
public:
    vector<string> answer;

    void dfs(TreeNode* node, string current){
        string val = to_string(node->val);

        if (node->left == NULL && node->right == NULL){
            answer.push_back(current + val);
            return;
        }

        if (node->left != NULL){
            dfs(node->left, current + val + "->");
        }

        if (node->right != NULL){
            dfs(node->right, current + val + "->");
        }

        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root != NULL){
            dfs(root, "");
        }

        return answer;
    }
};