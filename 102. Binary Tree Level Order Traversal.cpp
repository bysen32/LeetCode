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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<TreeNode*> rec,temp;
        rec.push_back(root);
        while( true ) {
            vector<int> one;
            temp.clear();
            for(int i=0; i<rec.size(); ++i) {
                if( rec[i]==NULL ) {
                    continue;
                }
                temp.push_back(rec[i]->left);
                temp.push_back(rec[i]->right);
                one.push_back(rec[i]->val);
            }
            if(not one.empty()) {
                ret.push_back(one);
            }
            if(temp.empty()) {
                break;
            }
            else {
                rec = temp;
            }
        }
        return ret;
    }
};
