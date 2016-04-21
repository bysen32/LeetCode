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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root != NULL) {
            vector<int> left = this->inorderTraversal(root->left);
            ans.insert(ans.begin(), left.begin(), left.end());
            ans.push_back(root->val);
            vector<int> right = this->inorderTraversal(root->right);
            ans.insert(ans.end(), right.begin(), right.end());
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while (!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;
            }
            else {
                ans.push_back(st.top()->val);
                root = st.top()->right;
                st.pop();
            }
        }
        return ans;
    }
};
