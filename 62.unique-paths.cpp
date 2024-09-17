/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
  public:
    int uniquePaths(int m, int n) {
        vector<int> up(n, 1);
        for (int r = 1; r < m; r++) {
            int left = 1;
            for (int c = 1; c < n; c++) {
                up[c] += left;
                left = up[c];
            }
        }

        return up[n - 1];
    }
};
// @lc code=end
