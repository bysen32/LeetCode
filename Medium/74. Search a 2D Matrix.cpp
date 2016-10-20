class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n*m, mid;
        while (left < right) {
            mid = (left+right)/2;
            if (matrix[mid/m][mid%m]==target) {
                return true;
            }
            else if (matrix[mid/m][mid%m]>target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return false;
    }
};
