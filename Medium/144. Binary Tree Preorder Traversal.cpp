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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root != NULL) {
            ans.push_back(root->val);
            vector<int> left = this->preorderTraversal(root->left);
            vector<int> right = this->preorderTraversal(root->right);
            ans.insert(ans.end(), left.begin(), left.end());
            ans.insert(ans.end(), right.begin(), right.end());
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node;
        if (root != NULL) {
            st.push(root);
        }
        while (!st.empty()) {
            node = st.top();
            ans.push_back(node->val);
            st.pop();
            if (node->right!=NULL) {
                st.push(node->right);
            }
            if (node->left!=NULL) {
                st.push(node->left);
            }
        }
        return ans;
    }
};
