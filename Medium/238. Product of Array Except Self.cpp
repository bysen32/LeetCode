class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(1, 1);
        int temp = 1;
        for (int i = 1; i < nums.size(); ++i) {
            temp *= nums[i-1];
            ans.push_back(temp);
        }
        temp = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] = ans[i] * temp;
            temp *= nums[i];
        }
        return ans;
    }
};

/*
题意:
	给定一个数组，将其每个元素转变为除此元素外所有元素的乘积。
	时间复杂度O(n), 空间复杂度O(1); 
题解:
	正确理解题意中，不使用额外空间的含义。
	使用返回值的空间，达到空间复杂度O(1)。 
	 
*/
