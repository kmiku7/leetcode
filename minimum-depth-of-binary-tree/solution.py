# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# 注意叶节点的定义TOT
class Solution:
    # @param root, a tree node
    # @return an integer
    def minDepth(self, root):
        if root is None:
            return 0
        current_level = [root]
        next_level = []
        shortest_path = 1
        while True:
            for item in current_level:
                if item.left is None and item.right is None:
                    return shortest_path
                if item.left is not None:
                    next_level.append(item.left)
                if item.right is not None:
                    next_level.append(item.right)
            current_level, next_level = next_level, []
            shortest_path += 1

