class Solution {
	public:
		int firstUniqChar(string s) {
			vector<int> rec(256, 0);
			for (int i = 0; i < s.size(); ++i) {
				rec[s[i]]++;
			}
			for (int i = 0; i < s.size(); ++i) {
				if (rec[s[i]] == 1) {
					return i;
				}
			}
			return -1;
		}
};
