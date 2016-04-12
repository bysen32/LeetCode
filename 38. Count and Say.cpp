class Solution {
public:
    string countAndSay(int n) {
        string cur, ans="1";
        int cnt;
        char flag;
        for ( int i=1; i<n; i++ ) {
            cur="";
            flag = ans[0];
            cnt = 1;
            for ( int j=1; j<ans.size(); ++j ) {
                if ( ans[j]==flag ) {
                    cnt+=1;
                }
                else {
                    cur += to_string(cnt) + flag;
                    flag = ans[j];
                    cnt = 1;
                }
            }
            cur += to_string(cnt) + flag;
            ans=cur;
        }
        return ans;
    }
};
