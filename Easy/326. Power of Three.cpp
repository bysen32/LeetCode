class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (1162261467 % n == 0);
    }
};
/*
解法多样，可递归可迭代
可用数学方法，如上或用对数求解
*/ 
