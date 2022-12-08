'''
' leetcode - 872
' tree, DFS, binary tree
'''

class Solution:
    def search_leaf_node(self, node: Optional[TreeNode]):
        if node is None:
            return []
        if node.left is None and node.right is None:
            return [node.val]
        return self.search_leaf_node(node.left) + self.search_leaf_node(node.right)

    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        result1 = self.search_leaf_node(root1)
        result2 = self.search_leaf_node(root2)
        return result1 == result2