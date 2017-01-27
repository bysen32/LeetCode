# 题意:
# 在BST中删除元素

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        if not root:
            return None
        if root.val > key:
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        else:
            if root.left == None:
                return root.right
            if root.right == None:
                return root.left
            maxNode = self.FindMax(root.left)
            root.val = maxNode.val
            root.left = self.deleteNode(root.left, root.val)
        return root

    def FindMax(self, root):
        while True:
            if root and root.right:
                root = root.right
            else:
                return root

    def FindMin(self, root):
        while True:
            if root and root.left:
                root = root.left
            else:
                return root

