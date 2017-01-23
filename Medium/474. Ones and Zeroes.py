# 474. Ones and Zeroes
# 题目大意:
# 给定由0,1字符组成的字符串集合，求取集合众字符串数量的最大值
# 要求最多m个0字符,最多n个1字符
# 题解:
# 等价于经典的背包问题: 二维费用背包问题
class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0 for i in range(n+1)] for j in range(m+1)]
        for s in strs:
            c0 = s.count("0")
            c1 = s.count("1")
            for i in range(m, -1, -1):
                for j in range(n, -1, -1):
                    if i - c0 >= 0 and j - c1 >= 0:
                        dp[i][j] = max(dp[i][j], dp[i-c0][j-c1] + 1)
                    else:
                        break
        return dp[m][n]
