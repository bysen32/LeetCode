class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while( n ) {
            ans = char('A'+(n-1)%26)+ans;
            n=(n-1)/26;
        }
        return ans;
    }
};
/*
简单的字符转化。考虑进1有点烦。 
*/
