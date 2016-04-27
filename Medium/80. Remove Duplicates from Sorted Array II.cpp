class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 2, sidx = 2, cnt = nums.size();
        while (idx < nums.size()) {
            if (nums[idx] == nums[sidx - 1] && nums[idx] == nums[sidx - 2]) {
            }
            else {
                swap(nums[sidx], nums[idx]);
                sidx += 1;
            }
            idx += 1;
        }
        int size = nums.size();
        sidx = min(sidx, size);
        return sidx;
    }
};

/*¸üÓÅ½â*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for (int num : nums) {
            if (idx < 2 || num != nums[idx - 2]) {
                nums[idx] = num;
                idx += 1;
            }
        }
        return idx;
    }
};

