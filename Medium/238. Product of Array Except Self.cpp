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
����:
	����һ�����飬����ÿ��Ԫ��ת��Ϊ����Ԫ��������Ԫ�صĳ˻���
	ʱ�临�Ӷ�O(n), �ռ临�Ӷ�O(1); 
���:
	��ȷ��������У���ʹ�ö���ռ�ĺ��塣
	ʹ�÷���ֵ�Ŀռ䣬�ﵽ�ռ临�Ӷ�O(1)�� 
	 
*/
