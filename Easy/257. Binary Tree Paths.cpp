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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans, temp;
        if(root==NULL) {
            return ans;
        }
        temp = binaryTreePaths(root->left);
        for(int i=0; i<temp.size(); ++i) {
            ans.push_back(to_string(root->val)+"->"+temp[i]);
        }
        temp = binaryTreePaths(root->right);
        for(int i=0; i<temp.size(); ++i) {
            ans.push_back(to_string(root->val)+"->"+temp[i]);
        }
        if(ans.empty()) {
            ans.push_back(to_string(root->val));
        }
        return ans;
    }
};

/*
写得不是很好看，只是把思路实现了一下。 
一个新函数to_string。 
*/
