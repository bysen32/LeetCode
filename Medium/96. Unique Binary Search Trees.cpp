class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(2, 1);
        for (int i = 2; i <= n; ++i) {
            dp.push_back(0);
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

/*
题意:
	N个不同元素能形成多少棵不同的二叉树。
题解:
	DP求解 时间复杂度:O(N^2) 
*/ 
