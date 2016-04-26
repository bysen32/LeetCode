class Solution {
public:
    int uniquePaths(int m, int n) {
        n -= 1;
        m -= 1;
        int N = m + n;
        long long ans = 1, k = 2;
        for (int i = n + 1; i <= N; ++i) {
            ans *= i;
            while (ans % k == 0 && k <= m) {
                ans /= k;
                k += 1;
            }
        }
        return ans;
    }
};
