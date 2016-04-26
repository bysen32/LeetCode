class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> record;
        for (int i = 1; i <= min(9, n); ++i) {
            record.push_back(i);
            generate(ans, record, i + 1, k - 1, n - i);
            record.pop_back();
        }
        return ans;
    }
    
    void generate(vector<vector<int>>& ans, vector<int>record, int begin, int k, int n) {
        if (k == 0 && n == 0) {
            ans.push_back(record);
            return;
        }
        for (int i = begin; i <= min(9, n); ++i) {
            record.push_back(i);
            generate(ans, record, i + 1, k - 1, n - i);
            record.pop_back();
        }
    }
}; 
