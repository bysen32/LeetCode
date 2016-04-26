class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(2, vector<int> (n, 0));
        int line = 0;
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; ++i) {
            dp[line][i] = dp[line][i - 1] + grid[0][i];
        }
        line ^= 1;
        for (int i = 1; i < m; ++i) {
            dp[line][0] = grid[i][0] + dp[line^1][0];
            for (int j = 1; j < n; ++j) {
                dp[line][j] = grid[i][j] + min(dp[line^1][j], dp[line][j - 1]);
            }
            line^=1;
        }
        return dp[line^1][n-1];
    }
};
