# 题目大意:
# 给定由1到n组成n+1个正整数的序列。此序列中存在一个重复数字，找出来。

class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) >= 2:
            slow = nums[0]
            fast = nums[slow]
            while slow != fast:
                slow = nums[slow]
                fast = nums[nums[fast]]
            slow = 0
            while slow != fast:
                slow = nums[slow]
                fast = nums[fast]
            return slow
        else:
            return -1

