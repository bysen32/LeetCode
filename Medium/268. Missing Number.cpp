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
����:
	����[0, 1, 2, ..., n]�����У�����ȱ��һ��Ԫ��X���ҳ�X��
���:
	XOR�����á� 
*/
