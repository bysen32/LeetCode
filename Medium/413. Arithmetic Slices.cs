/* 题意
 * 找规律 凑题数
 */
public class Solution {
    public int NumberOfArithmeticSlices(int[] A) {
        int pre = 2;
        int ret = 0;
        for(int i = 2; i < A.Length; ++i)
        {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                ret += pre - 1;
                pre += 1;
            }
            else
            {
                pre = 2;
            }
        }
        return ret;
    }
}
