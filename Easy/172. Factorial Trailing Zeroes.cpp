class Solution {
public:
    int trailingZeroes(int n) {
        if ( n ) {
            return n / 5 + trailingZeroes(n / 5);
        }
        return 0;
    }
};
