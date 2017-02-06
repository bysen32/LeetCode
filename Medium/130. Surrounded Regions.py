# 题意:
# 由X和O组成的2D字符矩阵，当O完全被X包围时，将这些O填充为X。
# 思路:
# 正向搜索超时，可以转变思路由边沿O向中间“渗透”。
# 得到一个可渗透点的访问数组，将不可访问的点都置为X即可
class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        r, c = len(board), len(board[0])
        self.vis = [[0 for i1 in range(c)] for i2 in range(r)]
        for i in range(r):
            if board[i][0] == 'O' and self.vis[i][0] == 0:
                self.Visit(board, i, 0)
            if board[i][c-1] == 'O' and self.vis[i][c-1] == 0:
                self.Visit(board, i, c-1)
        for i in range(c):
            if board[0][i] == 'O' and self.vis[0][i] == 0:
                self.Visit(board, 0, i)
            if board[r-1][i] == 'O' and self.vis[r-1][i] == 0:
                self.Visit(board, r-1, i)
        for i in range(r):
            for j in range(c):
                if self.vis[i][j] == 0:
                    board[i][j] = 'X'

    def Visit(self, board, i, j):
        r, c = len(board), len(board[0])
        queue = []
        queue.append((i,j))
        while len(queue)>0:
            i, j = queue.pop()
            self.vis[i][j] = 1
            if i+1 < r and board[i+1][j] == 'O' and self.vis[i+1][j] == 0:
                queue.append((i+1,j))
            if i-1 >= 0 and board[i-1][j] == 'O' and self.vis[i-1][j] == 0:
                queue.append((i-1,j))
            if j+1 < c and board[i][j+1] == 'O' and self.vis[i][j+1] == 0:
                queue.append((i,j+1))
            if j-1 >= 0 and board[i][j-1] == 'O' and self.vis[i][j-1] == 0:
                queue.append((i,j-1))

