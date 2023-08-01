class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0, r = rows - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (matrix[mid][0] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        int row = l - 1;
        if (row == -1 || matrix[row][0] > target) return false;
        l = 0, r = cols - 1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (matrix[row][mid] > target)
                r = mid - 1;
            else if (matrix[row][mid] < target)
                l = mid + 1;
            else
                return true;
        }
        return false;
    }
};