# 题意
# 有4个数组 A,B,C,D 最长500
# 在每个数组共取一个数，求4个数之和为0的取法数
# 题解
# 对AB, CD分别计算所有可能的组合，然后反向寻找，和的个数。
class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        dct = {}
        ret = 0
        for a in A:
            for b in B:
                dct[a+b] = dct.get(a+b, 0) + 1
        for c in C:
            for d in D:
                ret += dct.get(-c-d, 0)
        return ret
                    
    
