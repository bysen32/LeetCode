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
����:�ж���������������Ȳ��1��ƽ�� 
���:����һ�¡���Ϊ��ϣ�������int����ƽ���ж�����һ������ֵ�б�ʾ��
	������գ����ǿ��������꣬�������ٺú�����⡣ 
*/
