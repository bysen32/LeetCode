/** Problem Solution
 * Problem: Given one array of Coins, different denemination.
 * Ask the fewest number of coins to make up that amount.
 *
 * Example: coins = [1,2,5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 *
 * Solution:
 * dp formation: dp[v] = min(dp[val], dp[val-coin] + 1)
 * **/
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount+1, amount+1);
		dp[0] = 0;
		//sort(coins.begin(), coins.end(), greater<int>);
		for (int i = 0; i < coins.size(); ++i) {
			for (int j = coins[i]; j <= amount; ++j) {
				dp[j] = min(dp[j], dp[j-coins[i]]+1);
			}
		}
		if (dp[amount] == amount + 1) {
			return -1;
		}
		else {
			return dp[amount];
		}
	}
};
