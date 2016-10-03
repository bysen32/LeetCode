class Solution {
public:
    int integerReplacement(int n) {
        return integerReplacement((long)n);
    }
    int integerReplacement(long n) {
        if (n <= 1) {
            return 0;
        }
        if ((n&1) == 0) {
            return integerReplacement(n>>1) + 1;
        }
        else {
            return min(integerReplacement(n+1), integerReplacement(n-1))+1;
        }
    }
};
