class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            result ^= i;
            result ^= nums[i];
        }
        return result;
    }
};

/*
题意:
	给定[0, 1, 2, ..., n]的序列，其中缺少一个元素X，找出X。
题解:
	XOR的妙用。 
*/
