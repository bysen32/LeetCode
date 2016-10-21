class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int n = board.size(), m = board[0].size();
		vector<int> preline, curline;
		for (int i = 0; i<n; ++i) {
			curline = board[i];
			for (int j = 0; j<m; ++j) {
				int cnt = 0;
				for (int ii = i - 1; ii <= i + 1; ++ii) {
					for (int jj = j - 1; jj <= j + 1; ++jj) {
						if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
							if (ii == i - 1) {
								cnt += preline[jj];
							}
							else if (ii == i) {
								cnt += curline[jj];
							}
							else {
								cnt += board[ii][jj];
							}
						}
					}
				}
				cnt -= board[i][j];
				if (cnt<2 || cnt>3) {
					board[i][j] = 0;
				}
				if (cnt == 3) {
					board[i][j] = 1;
				}
			}
			preline = curline;
		}
	}
};