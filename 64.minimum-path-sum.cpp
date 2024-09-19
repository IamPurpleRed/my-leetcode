/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[r].size(); c++) {
                if (r == 0 && c == 0) continue;
                else if (r == 0) grid[r][c] += grid[r][c - 1];
                else if (c == 0) grid[r][c] += grid[r - 1][c];
                else grid[r][c] += min(grid[r][c - 1], grid[r - 1][c]);
            }
        }

        return *((grid.end() - 1)->end() - 1);
    }
};
// @lc code=end
