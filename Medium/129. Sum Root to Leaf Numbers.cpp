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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }
    
    void helper(TreeNode* root, int record, int& sum) {
        if (root == NULL) {
            return;
        }
        record += root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += record;
            return;
        }
        helper(root->left, record * 10, sum);
        helper(root->right, record * 10, sum);
    }
};
