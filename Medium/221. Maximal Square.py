# 题意:
# 由0和1组成的矩阵，求其中由1组成的正方形最大面积。
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix:
            return 0
        r, c = len(matrix), len(matrix[0])
        dp = [[0 for i in range(c)] for j in range(r)]

        ans = 0
        for i in range(r):
            dp[i][0] = 1 if matrix[i][0] == '1' else 0
            ans = max(ans, dp[i][0])
        for i in range(c):
            dp[0][i] = 1 if matrix[0][i] == '1' else 0
            ans = max(ans, dp[0][i])

        for i in range(1, r):
            for j in range(1, c):
                if matrix[i][j] == '1':
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1
                    ans = max(ans, dp[i][j])

        return ans * ans
