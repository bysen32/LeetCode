class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> vis;
        vector<int> record;
        helper(ans, nums, record, vis);
        return ans;
    }
    
    void helper(vector<vector<int>>& ans, vecotr<int> nums, vector<int> record, vector<bool> vis) {
        if (record.size() == nums.size()) {
            ans.push_back(record);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i] == false) {
                vis[i] = true;
                record.push_back(i);
                helper(ans, nums, record, vis);
                record.pop_back();
                vis[i] = false;
            }
        }
    }
};

/*递归版*/ 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, 0, ans);
        return ans;
    }
    
    void helper(vector<int> nums, int depth, vector<vector<int>>& ans) {
        if (depth == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = depth; i < nums.size(); ++i) {
            swap(nums[i], nums[depth]);
            helper(nums, depth+1, ans);
            swap(nums[i], nums[depth]);
        }
    }
};

/*迭代版*/ 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        for (int num : nums) {
            vector<vector<int>> templst;
            for (int j = 0; j < ans.size(); ++j) {
                for (int k = 0; k <= ans[j].size(); ++k) {
                    temp.clear();
                    temp.insert(temp.begin(), ans[j].begin(), ans[j].end());
                    temp.insert(temp.begin()+k, num);
                    templst.push_back(temp);
                }
            }
            ans = templst;
        }
        return ans;
    }
};
/*
题意:
	生成全排列
题解:
	解法2很巧妙。 
*/
