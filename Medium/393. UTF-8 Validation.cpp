class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int idx = 0;
        while (idx < data.size()) {
            int bitcnt = 0;
            auto num = data[idx];
            for (int i=0x80; i; i>>=1) {
                if (num&i) {
                    bitcnt += 1;
                }
                else {
                    break;
                }
            }
            if (bitcnt == 1 || bitcnt > 4) {
                return false;
            }
            idx++;
            for (int i=1; i<bitcnt; ++i) {
                if (idx >= data.size()) {
                    return false;
                }
                if (((data[idx]>>6)^2)!=0) {
                    return false;
                }
                idx++;
            }
        }
        return true;
    }
};