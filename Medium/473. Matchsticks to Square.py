# 题意:
# 给定最多15根火柴棍，问是否能恰好拼出一个正方形
# 思路:
# dfs + 优化

class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if not nums or len(nums) < 4:
            return False
        if sum(nums) % 4 != 0:
            return False
        self.edgeLen = sum(nums) / 4
        self.HadAns = False
        nums = sorted(nums, reverse=True)
        if nums[0] <= self.edgeLen:
            vis = [0 for i in range(len(nums))]
            vis[0] = 1
            self.dfs(nums, vis, 1, nums[0] % self.edgeLen)
        return self.HadAns

    def dfs(self, nums, vis, numcnt, rec):
        if numcnt == len(nums):
            if rec == 0:
                self.HadAns = True
            return

        for i in range(len(nums)):
            if self.HadAns:
                return
            if vis[i] == 0 and (rec + nums[i]) <= self.edgeLen:
                vis[i] = 1
                self.dfs(nums, vis, numcnt+1, (rec + nums[i]) % self.edgeLen)
                vis[i] = 0
