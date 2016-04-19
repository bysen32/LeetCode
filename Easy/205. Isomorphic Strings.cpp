class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if ( s.size()!=t.size() ) {
            return false;
        }
        unordered_map<char, char> smap, tmap;
        for ( int i=0; i<s.size(); ++i ) {
            if ( smap.find(s[i])==smap.end() ) {
                smap[s[i]]=t[i];
            }
            if ( smap[s[i]]!=t[i]) {
                return false;
            }
            if ( tmap.find(t[i])==tmap.end() ) {
                tmap[t[i]]=s[i];
            }
            if ( tmap[t[i]]!=s[i]) {
                return false;
            }
        }
        return true;
    }
};
/*
Code is so long in order to test STL unordered_map;
*/
