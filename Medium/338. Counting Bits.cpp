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
题意: 
	计算[0,n]中各个数字2进制表示中，1出现的次数。
题解:
	二叉树的活用。 
 
*/
