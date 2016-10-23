class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26]={0}, src=0, ans=0;
        for (int i=0; i<s.size(); ++i) {
            int curIdx = s[i] - 'A';
            cnt[curIdx]+=1;

            int flagIdx = 0, flagCnt = 0;
            for(int i=0;i<26;i++) {
                if (flagCnt <= cnt[i]) {
                    flagCnt = cnt[i];
                    flagIdx = i;
                }
            }
            int len = i-src+1, curCnt = cnt[flagIdx];
            if (len - curCnt > k) {
                char DelChar = s[src];
                while(s[src] == DelChar) {
                    cnt[DelChar-'A']-=1;
                    src+=1;
                }
            }
            ans = max(ans, i-src+1);
        }
        return ans;
    }
};

// Second Solution 
class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[255] = {0}, maxCnt = 0, src = 0;
        for (int i=0; i<s.size(); ++i) {
            cnt[s[i]] += 1;
            maxCnt = max(maxCnt, cnt[s[i]]);
            if (i-src+1 - maxCnt > k) {
                cnt[s[src]] -= 1;
                src += 1;
            }
        }
        return s.size() - src;
    }
};
