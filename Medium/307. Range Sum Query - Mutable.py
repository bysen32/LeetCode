# 题意:
# 线段树区间和
# 思路:
# N年没有碰线段树了，没想到还能切出来。厉害厉害。哈哈哈。
class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.length = len(nums)
        self.tree = [0 for i in range(self.length<<2)]
        for i in range(self.length):
            self.SetVal(i, nums[i], 1, 0, self.length-1)

    def SetVal(self, i, val, cur, L, R):
        if L == R:
            self.tree[cur] = val
            return
        mid = L + ((R-L)>>1)
        if i <= mid:
            self.SetVal(i, val, cur<<1, L, mid)
        else:
            self.SetVal(i, val, cur<<1|1, mid+1, R)
        self.tree[cur] = self.tree[cur<<1] + self.tree[cur<<1|1]

    def GetVal(self, cur, i, j, L, R):
        if ( i <= L and R <= j ):
            return self.tree[cur]
        mid = L + ((R-L)>>1)
        if i > mid:
            return self.GetVal(cur<<1|1, i, j, mid+1, R)
        elif j <= mid:
            return self.GetVal(cur<<1, i, j, L, mid)
        else:
            return self.GetVal(cur<<1, i, j, L, mid) + self.GetVal(cur<<1|1, i, j, mid+1, R)

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        self.SetVal(i, val, 1, 0, self.length-1)

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.GetVal(1, i, j, 0, self.length-1)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
