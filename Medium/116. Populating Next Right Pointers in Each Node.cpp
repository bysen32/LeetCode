/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> que;
        que.push(root);
        while (!que.empty()) {
            queue<TreeLinkNode*> temp;
            while (!que.empty()) {
                root = que.front();
                que.pop();
                if (root == NULL) {
                    return;
                }
                
                if (que.empty()) {
                    root->next = NULL;
                }
                else {
                    root->next = que.front();
                }
                temp.push(root->left);
                temp.push(root->right);
            }
            que = temp;
        }
    }
};

/*
题意:
	给定平衡二叉树，将其转化为兄弟孩子表示法。 
*/
