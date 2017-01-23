/* 题意
 * 找中位数
 */
public class Solution {
    public int MinMoves2(int[] nums) {
        Array.Sort(nums);
        int ret = 0;
        for (int i = 0;i < nums.Length;++i) {
            ret += Math.Abs(nums[i] - nums[nums.Length/2]);
        }
        return ret;
    }
}
