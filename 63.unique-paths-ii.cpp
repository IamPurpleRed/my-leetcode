/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> up(n);
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) break;
            up[i] = 1;
        }
        for (int r = 1; r < m; r++) {
            int left = (obstacleGrid[r][0] == 1) ? 0 : up[0];
            up[0] = left;
            for (int c = 1; c < n; c++) {
                if (obstacleGrid[r][c] == 1) up[c] = 0;
                else up[c] += left;
                left = up[c];
            }
        }

        return up[n - 1];
    }
};
// @lc code=end
