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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        vector<TreeNode*> rec,temp;
        if( root!=NULL ) {
            rec.push_back(root);
        }
        while( not rec.empty() ) {
            temp.clear();
            vector<int> one;
            for( int i=0; i<rec.size(); ++i ) {
                if( rec[i]->left!=NULL ) {
                    temp.push_back(rec[i]->left);
                }
                if( rec[i]->right!=NULL ) {
                    temp.push_back(rec[i]->right);
                }
                one.push_back(rec[i]->val);
            }
            ret.insert(ret.begin(), one);
            rec=temp;
        }
        return ret;
    }
};
