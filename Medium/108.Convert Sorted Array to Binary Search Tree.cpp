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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }
        int n = nums.size();
        TreeNode* root = new TreeNode(nums[n / 2]);
        
        vector<int> temp;
        if (n / 2 > 0) {
            temp.insert(temp.begin(), nums.begin(), nums.begin() + n / 2);
            root->left = sortedArrayToBST(temp);
            temp.clear();
        }
        if (n / 2 + 1 < n) {
            temp.insert(temp.begin(), nums.begin() + n / 2 + 1, nums.end());
            root->right = sortedArrayToBST(temp);
        }
        return root;
    }
};

/*
题意:
	给定序列转化成二叉平衡树
题解:
	递归 
*/ 
