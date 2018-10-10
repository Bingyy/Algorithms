# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        que = [[root, 0]]
        record = {}
        layer = 0
        
        while que != []:
            [cur, layer] = que.pop(0)
            if cur:
                if layer not in record:
                    record[layer] = [cur.val]
                else:
                    record[layer] += [cur.val]
                que += [[cur.left,layer + 1], [cur.right, layer + 1]]
        
        # while que != []:
        #     [cur, layer] = que.pop(0)
        #     if cur != None:
        #         if layer not in record:
        #             record[layer] = [cur.val]
        #         else:
        #             record[layer] += [cur.val]
        #         que += [[root.left, layer + 1], [root.right, layer + 1]] # 这里写成了root.left,应当是cur
    
        # 将字典中数据提取到数组
        res = [None] * len(record)
        for key, val in record.items():
            res[key] = val[-1]
        return res
     
