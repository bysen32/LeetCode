class Solution {
public:
    bool isValid(string s) {
        stack<char> stack1;
        map<char, char> dict;
        dict['(']=')';
        dict['[']=']';
        dict['{']='}';
        for ( int i=0; i<s.size(); i++ ) {
            if ( s[i] == '(' || s[i] == '{' || s[i] == '[' ) {
                stack1.push(s[i]);
            }
            else if ( stack1.empty() || dict[stack1.top()]!=s[i] ) {
                return false;
            }
            else {
                stack1.pop();
            }
        }
        return stack1.empty();
    }
};
