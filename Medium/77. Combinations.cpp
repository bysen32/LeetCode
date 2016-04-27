class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> record;
        helper(ans, record, 1, n, k);
        return ans;
    }
    
    void helper(vector<vector<int>>& ans, vector<int> record, int begin, int n, int depth) {
        if (depth == 0) {
            ans.push_back(record);
            return;
        }
        for (int i = begin; i <= n; ++i) {
            record.push_back(i);
            helper(ans, record, i + 1, n, depth - 1);
            record.pop_back();
        }
    }
};
