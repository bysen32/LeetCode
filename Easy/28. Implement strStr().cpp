class Solution {
public:
    int strStr(string haystack, string needle) {
        bool bfind;
        int m=haystack.size(), n=needle.size();
        if ( n==0 ) {
            return 0;
        }
        for( int i=0; i<m-n+1; ++i ) {
            bfind=true;
            for ( int j=0; j<n; ++j ) {
                if( needle[j]!=haystack[i+j] ) {
                    bfind=false;
                    break;
                }
                
                
            }
            if (bfind) {
                return i;
            }
        }
        return -1;
    }
};
