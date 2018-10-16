# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.max_path = 0
        if root == None:
            return 0
        self.recursive_find(root)
        return self.max_path
    
    def recursive_find(self,root):
        if root == None:
            return 0
        left = self.recursive_find(root.left)
        right = self.recursive_find(root.right)
        if (root.left != None and root.val == root.left.val):
            left +=  1
        elif (root.left != None): # 只是非空
            left = 0
        if (root.right != None and root.val == root.right.val):
            right += 1
        elif (root.right != None):
            right = 0
        if left + right > self.max_path:
            self.max_path = left + right
            
        return max(left, right)
