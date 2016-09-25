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
    int sumOfLeftLeaves(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        if (isLeave(root->left)) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        else {
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
    }
    
    bool isLeave(TreeNode* root) {
        if (root && NULL == root->left && NULL == root->right) {
            return true;
        }
        return false;
    }
};
