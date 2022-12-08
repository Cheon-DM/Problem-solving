'''
' leetcode - 938
' tree, DFS, BST, binary tree
'''

class Solution:
    def __init__(self):
        self.answer = 0

    def search_range_node(self, node: Optional[TreeNode], low: int, high: int):
        if node is None: return
        elif node.val >= low and node.val <= high:
            self.answer += node.val
            self.search_range_node(node.left, low, high)
            self.search_range_node(node.right, low, high)
        elif node.val < low:
            self.search_range_node(node.right, low, high)
        elif node.val > high:
            self.search_range_node(node.left, low, high)
            
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.search_range_node(root, low, high)        
        return self.answer