/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
  public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int height = matrix.size();
        const int width = matrix[0].size();
        for (int r = 1; r < height; r++) {
            if (width == 1) matrix[r][0] += matrix[r - 1][0];
            else {
                for (int c = 0; c < width; c++) {
                    if (c == 0)
                        matrix[r][c] +=
                            min(matrix[r - 1][c], matrix[r - 1][c + 1]);
                    else if (c == width - 1)
                        matrix[r][c] +=
                            min(matrix[r - 1][c], matrix[r - 1][c - 1]);
                    else
                        matrix[r][c] += min(
                            matrix[r - 1][c],
                            min(matrix[r - 1][c - 1], matrix[r - 1][c + 1]));
                }
            }
        }
        sort(matrix[height - 1].begin(), matrix[height - 1].end());

        return matrix[height - 1][0];
    }
};
// @lc code=end
