/* 题意:
 * 将给定字符串以单词为单位进行反转。
 * 例: "the sky is blue" => "blue is sky the"
 * 考虑细节!!
 */
#include<iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        int i, j;
        i = j = 0;
        while (true) {
            while (i < len && s[i] == ' ') {
                i += 1;
            }
            if (i == len) {
                break;
            }
            j = i + 1;
            while (j < len && s[j] != ' ') {
                j += 1;
            }
            reverseWords(s, i, j - 1);
            i = j;
        }
        reverseWords(s, 0, len - 1);
        CleanSpaces(s);
    }
    
    void reverseWords(string &s, int i, int j) {
        while (i < j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            i += 1;
            j -= 1;
        }
    }
    
    void CleanSpaces(string &s) {
        int len = s.length();
        int i, j;
        i = j = 0;
        bool spaceEnable = false;
        bool hasWord = false;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                spaceEnable = true;
            }
            else {
                if (hasWord && spaceEnable) {
                    s[j] = ' ';
                    j += 1;
                }
                hasWord = true;
                spaceEnable = false;
                s[j] = s[i];
                j += 1;
            }
        }
        s.resize(j);
    }
};
