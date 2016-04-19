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
    bool isBalanced(TreeNode* root) {
        if( getDepth(root)==-1 ) {
            return false;
        }
        else {
            return true;
        }
    }
    int getDepth(TreeNode* root) {
        if( root == NULL ) {
            return 0;
        }
        int depthL, depthR;
        depthL = getDepth(root->left);
        depthR = getDepth(root->right);
        if( depthR == -1 || depthL == -1 ) {
            return -1;
        }
        else if( abs(depthL-depthR)>1 ){
            return -1;
        }
        else {
            return max(depthL, depthR)+1;
        }
    }
};
/*
题意:判定二叉树的子树深度差超过1则不平衡 
题解:卡了一下。因为不希望将深度int，与平衡判定放在一个返回值中表示。
	最后作罢，还是快速先做完，切难题再好好做题解。 
*/
