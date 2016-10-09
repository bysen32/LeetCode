class Solution {
public:
    string decodeString(string s) {
        string num = "", abc = "", ret = "";
        int cnt = 0;
        for ( int i = 0; i < s.size(); ++i ) {
            if ( '0' <= s[i] && s[i] <= '9' && cnt == 0) {
                num += s[i];
                continue;
            }
            if ( s[i] == '[' ) {
                cnt += 1;
            }
            if (cnt) {
                abc += s[i];
            }
            else {
                ret += s[i];
            }
            if ( s[i] == ']' ) {
                cnt -= 1;
                if ( cnt == 0 ) {
                    string temp = decodeString(abc.substr(1, abc.size()-2));
                    for ( int i = 0; i < atoi(num.c_str()); ++i ) {
                        ret += temp;
                    }
                    num = "";
                    abc = "";
                }
            }
        }
        ret += abc;
        return ret;
    }
};
