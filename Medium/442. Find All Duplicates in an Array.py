# 题意
# 整型数组长度为N,且其中元素值范围为[1,N],其中元素最多重复出现两次
# 找到所有重复出现的元素，要求无额外空间，时间O(n)
# 解题思路，利用现有空间，在不破坏（可恢复）的情况下保存判断依据

class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = []
        for num in nums:
            if nums[abs(num) - 1] < 0:
                ret.append(abs(num))
            else:
                nums[abs(num) - 1] *= -1
        return ret
