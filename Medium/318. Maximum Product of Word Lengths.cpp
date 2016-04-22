class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bitmask;
        int ans = 0;
        for (int i = 0; i < words.size(); ++i) {
            bitmask.push_back(0);
            for (int j = 0; j < words[i].size(); ++j) {
                bitmask[i] |= 1<<(words[i][j]-'a');
            }
        }
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if ((bitmask[i] & bitmask[j]) == 0) {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};
