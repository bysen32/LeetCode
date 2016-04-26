/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> que;
        if (root == NULL) {
            return ans;
        }
        que.push(root);
        while (!que.empty()) {
            queue<TreeNode*> temp;
            while (!que.empty()) {
                root = que.front();
                que.pop();
                if (que.empty()) {
                    ans.push_back(root->val);
                }
                if (root->left) {
                    temp.push(root->left);
                }
                if (root->right) {
                    temp.push(root->right);
                }
            }
            que = temp;
        }
        return ans;
    }
};

/*dfs*/
class Solution {
public:
    void dfs(TreeNode* root, int lv, vector<int> &res){
        if(!root)   return;
        if(lv>=res.size()) res.push_back(root->val);
        dfs(root->right,lv+1,res);
        dfs(root->left,lv+1,res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};
