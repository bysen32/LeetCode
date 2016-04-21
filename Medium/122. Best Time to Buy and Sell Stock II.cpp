class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size();
        int min = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (prices[i] < min) {
                min = prices[i]; // lower prices
            }
            if (i == n - 1 || prices[i] > prices[i + 1]) { //Price Top Point
                if (prices[i] > min) { //to sell one stocks && reset prices
                    ans += prices[i] - min;
                    min = INT_MAX;
                }
            }
        }
        return ans;
    }
};

/*
题意:
	给定序列，计算区间最小值与区间最大值距离之和。 
题解: 
	模拟编码实现。 
*/
