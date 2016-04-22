class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(2, 1);
        for (int i = 2; i <= n; ++i) {
            dp.push_back(0);
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

/*
����:
	N����ͬԪ�����γɶ��ٿò�ͬ�Ķ�������
���:
	DP��� ʱ�临�Ӷ�:O(N^2) 
*/ 
