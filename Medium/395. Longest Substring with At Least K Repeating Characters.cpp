// 一种递归解法，上班路上突然想到的。
class Solution {
public:
    int longestSubstring(string s, int k) {
        int table[255] = {0};
        for (a : s) {
            table[a]+=1;
        }
        string temp = "";d
        int ans = 0;
        for (a : s) {
            if (table[a] < k) {
                if (temp.size()) {
                    ans = max(ans, longestSubstring(temp, k));
                    temp = "";
                }
            }
            else {
                temp += a;
            }
        }
        if (temp == s) {
            return temp.size();
        }
        else if(temp.size()) {
            ans = max(ans, longestSubstring(temp, k));
        }
        return ans;
    }
};
