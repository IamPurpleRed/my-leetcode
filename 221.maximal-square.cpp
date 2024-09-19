/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
  public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));  // (m + 1) * (n + 1)
        int ans = 0;                                        // 邊長
        for (int r = 1; r <= m; r++) {
            for (int c = 1; c <= n; c++) {
                if (matrix[r - 1][c - 1] == '1') {
                    dp[r][c] =
                        1 + min({dp[r - 1][c], dp[r - 1][c - 1], dp[r][c - 1]});
                    // 左、上、左上均要為 1，才能變成 2；均要為 2，才能變成 3
                    // 如果分別是 2, 2, 1，代表圍不出邊長為 3。只能圍出 2 = 1 +
                    // min(左, 上, 左上)
                }
                ans = max(ans, dp[r][c]);
            }
        }

        return ans * ans;  // 面積
    }
};
// @lc code=end
