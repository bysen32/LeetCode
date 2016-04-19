class Solution {
public:
    string addBinary(string a, string b) {
        string ret = "";
        int temp=0;
        int idxa = a.size()-1;
        int idxb = b.size()-1;
        while( idxa>=0 || idxb>=0 || temp!=0 ) {
            if( idxa >= 0 ) {
                temp += a[idxa] - '0';
                idxa -= 1;
            }
            if( idxb >= 0 ) {
                temp += b[idxb] - '0';
                idxb -= 1;
            }
            ret = char((temp&1) + '0') + ret;
            temp >>= 1;
        }
        return ret;
    }
};
