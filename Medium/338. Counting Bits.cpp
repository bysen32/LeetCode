class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        for (int i = 1; i <= num; ++i) {
            ans[i] = ans[i/2] + (i & 1);
        }
        return ans;
    }
};

/*
����: 
	����[0,n]�и�������2���Ʊ�ʾ�У�1���ֵĴ�����
���:
	�������Ļ��á� 
 
*/
