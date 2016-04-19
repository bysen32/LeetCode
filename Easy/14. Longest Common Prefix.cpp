class Solution {
public:
    string getCommonPrefix(string a, string b) {
        string prefix;
        for ( int i=0; i<min(a.size(), b.size()); ++i ) {
            if ( a[i]==b[i] ) {
                prefix += a[i];
            }
            else {
                return prefix;
            }
        }
        return prefix;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if (strs.empty()==false) {
            ans = strs[0];
            for ( int i=1; i<strs.size()&&ans.size(); ++i ) {
                ans = getCommonPrefix(ans, strs[i]);
            }
        }
        return ans;
    }
    
};
