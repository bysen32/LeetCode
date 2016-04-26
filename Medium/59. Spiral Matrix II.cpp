class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cnt = 1, x = 0, y = -1, ix, iy;
        vector<vector<int>> ans(n, vector<int> (n, 0));
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (cnt <= n * n) {
            for (int i = 0; i < 4; ++i) {
                ix = dir[i][0];
                iy = dir[i][1];
                while (x + ix < n && y + iy < n && x + ix >= 0 && y + iy >= 0 && ans[x + ix][y + iy] == 0) {
                    ans[x + ix][y + iy] = cnt;
                    cnt += 1;
                    x += ix;
                    y += iy;
                }
            }
        }
        return ans;
    }
};
