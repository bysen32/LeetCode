class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int idx=0;
        while (idx+1<nums.size()) {
            if ( nums[idx]==nums[idx+1] ) {
               nums.erase(nums.begin()+idx); 
            }
            else {
                idx+=1;
            }
        }
        return idx+1;
    }
};
