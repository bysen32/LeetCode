/* 题意:
 * 给定除数与被除数，计算商
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
        int sign = (divisor < 0) ^ (dividend < 0);
        long divisorL = labs(divisor);
        long dividendL = labs(dividend);
        int res = 0;
        while (dividendL >= divisorL) {
            for (int i = 31; i >= 0; --i) {
                if (dividendL >= (divisorL<<i)) {
                    dividendL -= (divisorL<<i);
                    res += (1<<i);
                }
            }
        }
        return sign == 0 ? res : -res;
    }
};
