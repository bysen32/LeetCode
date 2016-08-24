/** Problem Solution
 * Problem: Given 2D binary matrix fill with 0 and 1,
 * find the largest square	containing only 1 and return its area;
 * 
 * Example:
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Solution:
 * dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])+1
 * **/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
		vector<vector<int>> dp;
		for ( int i = 0; i < n; ++i ) {
			dp.push_back(vector<int> (m, 0));
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (matrix[i][j]=='1') {
					if (i == 0 || j == 0) {
						dp[i][j] = 1;
					}
					else {
						dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
					}
					ans = max(ans, dp[i][j]);
				}
			}
		}
		return ans*ans;
    }
};
