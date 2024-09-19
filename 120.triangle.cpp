/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
  public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = triangle[0][0];
        for (int r = 1; r < triangle.size(); r++) {
            for (int c = 0; c <= r; c++) {
                if (c == 0) {
                    triangle[r][c] += triangle[r - 1][c];
                    ans = triangle[r][c];
                    continue;
                } else if (c == r) triangle[r][c] += triangle[r - 1][c - 1];
                else
                    triangle[r][c] +=
                        min(triangle[r - 1][c], triangle[r - 1][c - 1]);
                ans = min(ans, triangle[r][c]);
            }
        }

        return ans;
    }
};
// @lc code=end
