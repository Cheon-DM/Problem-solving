#include <iostream>
#define fio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    int _max;
    int diameterOfBinaryTree(TreeNode* root) {
        _max = 0;
        maxDepth(root);
        return _max;
    }

    int maxDepth(TreeNode* node){
        if (node == NULL) return 0;
        
        int left = maxDepth(node->left);
        int right = maxDepth(node->right);
        _max = max(_max, left + right);

        return max(left, right) + 1;
    }
};