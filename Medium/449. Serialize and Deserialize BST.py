# 题意:
# 将二叉树序列化为字符串，反序列化还原
# 题解：
# 将顶点编号，存值

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        data = ""
        nodes = [(1, root)]
        while (len(nodes)>0):
            id, node = nodes.pop(0)
            if node:
                nodes.append((id<<1, node.left))
                nodes.append((id<<1|1, node.right))
                if data:
                    data += '|'
                data = data + str((id, node.val))
        return data

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        datas = data.split("|")
        dct = {}
        while (len(datas)>0):
            d = datas.pop(0)
            id, val = eval(d)
            dct[id] = val
        if dct.has_key(1):
            root = TreeNode(dct[1])
        else:
            root = None
            return root

        nodes = [(1, root)]
        while (len(nodes)>0):
            id, node = nodes.pop(0)
            if dct.has_key(id<<1):
                node.left = TreeNode(dct[id<<1])
                nodes.append((id<<1, node.left))
            if dct.has_key(id<<1|1):
                node.right = TreeNode(dct[id<<1|1])
                nodes.append((id<<1|1, node.right))
        return root

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
