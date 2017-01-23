class Solution {
public:
    int numSquares(int n) {
		int* nums = new int[n+1];
    	for (int i=1; i<=n; i++) {
    		nums[i] = i;
    		for (int j=1; i-j*j>=0; j++) {
    			if (i == j*j)
    				nums[i] = 1;
				else
	    			nums[i] = min(nums[i], nums[j*j] + nums[i-j*j]);
    		}
    	}
    	return nums[n];
    }
};

class Solution {
public:
	int numSquares(int n) {
		vector<int> nums({0});
		while ( nums.size() <= n) {
			int temp = INT_MAX;
			int m = nums.size();
			for(int i=1; i*i < m; ++i) {
				temp = min(temp, nums[m-i*i] + 1);
			}
			nums.push_back(temp);
		}
		return nums[n];
	}
}
