class Solution {
public:
    bool isPalindrome(string s) {
        vector<int> temp;
        for(int i=0; i<s.size(); ++i) {
            if('A'<=s[i] && s[i]<='Z') {
                temp.push_back(s[i]-'A');
            }
            else if('a'<=s[i] && s[i]<='z') {
                temp.push_back(s[i]-'a');
            }
            else if('0'<=s[i] && s[i]<='9') {
                temp.push_back(int(s[i]));
            }
        }
        for(int i=0; i<temp.size()/2; ++i) {
            if(temp[i]!=temp[temp.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};
/*
判定合法回文串。
字母表序居然有阿拉伯数字。 
*/ 
