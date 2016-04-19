class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        sum.clear();
        for(int i=0; i<nums.size(); ++i) {
            if(i==0) {
                sum.push_back(nums[0]);
            }
            else {
                sum.push_back(sum[i-1]+nums[i]);
            }
        }
    }

    int sumRange(int i, int j) {
        if(i==0) {
            return sum[j];
        }
        else {
            return sum[j]-sum[i-1];
        }
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
