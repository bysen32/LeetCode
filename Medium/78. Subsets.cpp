class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> record;
        vector<vector<int>> ans;
        dfs(nums, 0, record, ans);
        return ans;
    }
    
    void dfs(vector<int> nums, int begin, vector<int> record, vector<vector<int>>& ans) {
        ans.push_back(record);
        for (int i = begin; i < nums.size(); ++i) {
            record.push_back(nums[i]);
            dfs(nums, i + 1, record, ans);
            record.pop_back();
        }
    }
};
/*Normal Solution*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int m = 1<<n;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans(m, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (j & (1<<i)) {
                    ans[j].push_back(nums[i]);
                }
            }
        }
        return ans;
    }
};
/*Bit Manipulation*/
