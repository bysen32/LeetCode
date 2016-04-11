class Solution {
public:
    bool isPalindrome(int x) {
        if ( x<0 ) {
            return false;
        }
        int num=0, temp=x;
        while (temp) {
            num = num*10+temp%10;
            temp/=10;
        }
        return x==num;
    }
};
/*
There are so many trick, such as negetive isn't palindrome,
And 'without extra space' means to use O(1) space is enable! 
*/
