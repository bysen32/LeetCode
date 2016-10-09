class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret,ret1,ret2;
        for ( int i=0; i<input.size(); ++i ) {
            char c = input[i];
            vector<int> ret1, ret2;
            if( c == '+' || c == '-' || c == '*' ) {
                ret1 = diffWaysToCompute(input.substr(0, i));
                ret2 = diffWaysToCompute(input.substr(i+1, input.size()-i-1));
            }
            for ( int i = 0; i < ret1.size(); ++i )
            for ( int j = 0; j < ret2.size(); ++j )
            {
                if ( c == '+' ) {
                    ret.push_back(ret1[i] + ret2[j]);
                }
                else if ( c == '-' ) {
                    ret.push_back(ret1[i] - ret2[j]);
                }
                else if ( c == '*' ) {
                    ret.push_back(ret1[i] * ret2[j]);
                }
            }
        }
        if (ret.size() == 0) {
            ret.push_back(atoi(input.c_str()));
        }
        return ret;
    }
};