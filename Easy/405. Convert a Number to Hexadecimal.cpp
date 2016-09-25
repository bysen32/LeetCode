class Solution {
public:
    string toHex(int num) {
        string str = "";
        for ( int i = 0; num && i < 8; ++i ) {
            int bit = num & 0xf;
            if (bit < 10) {
                str = char(bit + '0') + str;
            }
            else {
                str = char(bit - 10 + 'a') + str;
            }
            num >>= 4;
        }
        return str.empty()?"0":str;
    }
};
