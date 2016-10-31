class Tried {
public:
    Tried *child[2] = {NULL};
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Tried *root = new Tried;
        for (num :nums) {
            Tried *node = root;
            for (int i=31; i>=0; --i) {
                int bit = (num>>i)&1;
                if (node->child[bit] == NULL) {
                    node->child[bit] = new Tried;
                }
                node = node->child[bit];
            }
        }
        int ans = INT_MIN;
        for (num : nums) {
            Tried *node = root;
            int temp = 0;
            for (int i=31; i>=0; --i) {
                int bit = (num>>i)&1;
                if (node->child[bit^1] != NULL) {
                    temp |= (1<<i);
                    node = node->child[bit^1];
                }
                else {
                    node = node->child[bit];
                }
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};
