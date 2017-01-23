/* 题意:
 * 给定序列，求序列项两两之间的哈密顿距离之和
 * 思路:
 * 裸解超时。
 * 换一个维度思考，计算所有数字同一位上的1的数量，同位置上的每个1与0将哈密顿距离+1。即为zeroNum*oneNum;
 * */
public class Solution {
	public int TotalHammingDistance(int[] nums) {
		int n = nums.Length;
		int sum = 0;
		for (int i = 0; i < 32; i++)
		{
			int bitCnt = 0;
			for (int j = 0; j < n; ++j)
				bitCnt += ((nums[j] >> i) & 1);
			sum += bitCnt * (n - bitCnt);
		}
		return sum;
	}
}
