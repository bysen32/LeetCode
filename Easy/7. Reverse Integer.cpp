class Solution {
public:
    int reverse(int x) {
        long long ret=0;
        while(x) {
            ret = ret*10 + x%10;
            x/=10;
        }
        if( ret > INT_MAX || ret < INT_MIN ) { //Notice!!! Out of Range!!!
            return 0;
        }
        else {
            return int(ret);
        }
    }
};
