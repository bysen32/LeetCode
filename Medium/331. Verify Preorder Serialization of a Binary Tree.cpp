class Solution {
    stack<int> stk;
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#") {
            return true;
        }
        string node = "";
        int idx = 0;
        for (; idx<preorder.size(); ++idx) {
            char s = preorder[idx];
            if (s==',') {
                node = "";
                continue;
            }
            if (s=='#') {
                node = "";
                if (stk.empty()) {
                    return false;
                }
                stk.top()+=1;
            }
            else if (node.size()) {
                node += s;
                continue;
            }
            else {
                node = s;
                stk.push(0);
            }
            while ((!stk.empty()) && stk.top()>=2 ) {
                if (stk.top()==2) {
                    stk.pop();
                    if (!stk.empty()) {
                        stk.top()+=1;
                    }
                }
                else {
                    return false;
                }
            }
            if (stk.empty() && idx != preorder.size()-1) {
                return false;
            }
        }
        return stk.empty();
    }
};
