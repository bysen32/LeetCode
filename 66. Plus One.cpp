class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int temp=1;
        if( digits.empty() ) {
            return digits;
        }
        for( int i=digits.size()-1; i>=0; --i ) {
            digits[i] = digits[i]+temp;
            temp = digits[i]/10;
            digits[i]%=10;
            if(temp==0) {
                return digits;
            }
        }
        if(temp) {
            digits.insert(digits.begin(), temp);
        }
        return digits;
    }
};
