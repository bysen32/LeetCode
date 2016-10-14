class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size+1, vector<int>(4,0x8fffffff));
        dp[0][3] = 0;
        for (int i=1; i<=size; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][3] - prices[i-1]);
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + prices[i-1];
            dp[i][2] = max(dp[i-1][0], dp[i-1][2]);
            dp[i][3] = max(dp[i-1][1], dp[i-1][3]);
        }
        return max(max(max(dp[size][0],dp[size][1]),dp[size][2]),dp[size][3]);
    }
};