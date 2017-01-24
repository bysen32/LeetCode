/* 题意：
 * 一串序列，A,B两玩家从两端轮次取数，求A是否能获胜。
 * 题解:
 * 使用DP对子序列进行状态压缩。
 * 转移方程：DP[i][j] = max(Sum[i][j] - DP[i-1][j], Sum[i][j] - DP[i][j-1])
 */
public class Solution {
    public bool PredictTheWinner(int[] nums) {
        int size = nums.Length;
        int[] preSum = new int[size];
        for (int i = 0; i < size; ++i)
            preSum[i] = nums[i] + (i == 0 ? 0 : preSum[i-1]);
        
        int[,] dp = new int[size, size];
        for (int offset = 0; offset < size; offset++)
        {
            for (int head = 0, tail = head + offset; tail < size; head++, tail++)
            {
                if (head == tail) {
                    dp[head, head] = nums[head];
                }
                else {
                    dp[head, tail] = Math.Max( nums[head] + GetSum(preSum, head + 1, tail) - dp[head + 1, tail],
                                           nums[tail] + GetSum(preSum, head, tail - 1) - dp[head, tail - 1]);
                }
            }
        }
        return dp[0, size - 1] >= (preSum[size-1] + 1)/ 2;
    }
    
    private int GetSum(int[] preSum, int i, int j) {
        return preSum[j] - (i - 1 >= 0 ? preSum[i - 1] : 0);
    }
}
