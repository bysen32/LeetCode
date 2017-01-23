/* 题意:
 * 非负整数序列，对各元素进行+,-运算求和，求出和为目标值的种类个数。
 * 如序列[1,1,1,1,1]目标值为3
 * 则有
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3 等，共5种。
 * 题解：
 * 很明显的动态规划题目。
 * */

// Solution.1 448ms
// 直接dp，第i个元素的状态由前i-1个元素的状态压缩转移而来。
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            nums[i] += nums[i];
        }
        if (S > sum)
            return 0;
        S += sum;
        int dp[S + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = S; j >= nums[i]; --j)
                dp[j] += dp[j - nums[i]];
        return dp[S];
    }
};

// Solution 2. 9ms 二维状态转移 第一维序列长度 第二维度求和值长度
// 将序列整体×2 目标值+原序列和。
// 原有操作 -序列项 +序列项 转化为
// 不使用该序列项 与 使用该序列项 变成一个基础的背包问题
// dp[i][target] = dp[i-1][target-num[i]] + dp[i-1][target];
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            nums[i] += nums[i];
        }
        if (S > sum)
            return S == sum ? 1 : 0;
        S += sum;
        int dp[nums.size()+1][S + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= nums.size(); ++i)
        {
            for (int j = 0; j <= S; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - nums[i - 1] >= 0)
                {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.size()][S];
    }
};
// Solution 3. 6ms 基于Solution 2.将第一维简化掉
//
//
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            nums[i] += nums[i];
        }
        if (S > sum)
            return 0;
        S += sum;
        int dp[S + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i)
            for (int j = S; j >= nums[i]; --j)
                dp[j] += dp[j - nums[i]];
        return dp[S];
    }
}
