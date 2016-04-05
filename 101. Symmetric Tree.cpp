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
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> rec,temp;
        if( root==NULL ) {
            return true;
        }
        rec.push_back(root);
        while( not rec.empty() ) {
            temp.clear();
            for( int i=0; i<rec.size(); ++i ) {
                if( rec[i] == NULL ) {
                    continue;
                }
                temp.push_back(rec[i]->left);
                temp.push_back(rec[i]->right);
            }
            for(int i=0; i<temp.size()/2; ++i ) {
                int p=temp.size()-i-1;
                if( temp[i]==NULL || temp[p]==NULL ) {
                    if( temp[i] || temp[p] ) {
                        return false;
                    }
                }
                else {
                    if( temp[i]->val != temp[p]->val ) {
                        return false;
                    }
                }
            }
            rec = temp;
        }
        return true;
    }
};
