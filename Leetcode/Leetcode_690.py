"""
# Employee info
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution:
    def getImportance(self, employees, id):
        """
        :type employees: Employee # 是个列表，列表中的数据类型是Employee
        :type id: int
        :rtype: int
        """
        dic = {} # 用于列表变字典
        total = 0
        for e in employees:
            dic[e.id] = [e.importance, e.subordinates]
        ids = [id] # 用于模拟queue
        while ids != [] :
            cur_id = ids.pop(0)
            total += dic[cur_id][0]
            ids += dic[cur_id][1]
        return total
        
        
