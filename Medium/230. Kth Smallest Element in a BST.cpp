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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;
        while (!stack.empty() || root!=NULL) {
            if (root) {
                stack.push(root);
                root = root->left;
            }
            else {
                root = stack.top();
                k -= 1;
                if (k == 0) {
                    return root->val;
                }
                root = root->right;
                stack.pop();
            }
        }
        return -1;
    }
};

/*
����:
	�����������е�KС��Ԫ�ء�
���:
	ʹ��ջʵ�ֶ�����ǰ������� 
*/ 
