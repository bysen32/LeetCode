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
    int minDepth(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int depth=0;
        vector<TreeNode*> rec,temp;
        rec.push_back(root);
        while(true) {
            temp.clear();
            depth+=1;
            for(int i=0; i<rec.size(); ++i){
                if(rec[i]->left==NULL && rec[i]->right==NULL) {
                    return depth;
                }
                if(rec[i]->left) {
                    temp.push_back(rec[i]->left);
                }
                if(rec[i]->right) {
                    temp.push_back(rec[i]->right);
                }
            }
            rec=temp;
        }
    }
};
/*
to conversation leaf node correctly! 
*/
