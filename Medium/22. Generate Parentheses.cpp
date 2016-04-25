class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, "", n, 0);
        return ans;
    }
    
    void dfs(vector<string> &vector, string temp, int n, int m) {
        if (n == 0 && m == 0) {
            vector.push_back(temp);
        }
        if (n > 0) {
            dfs(vector, temp + "(", n - 1, m + 1);
        }
        if (m > 0) {
            dfs(vector, temp + ")", n, m - 1);
        }
    }
};
