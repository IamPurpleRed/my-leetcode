/*
 * @lc app=leetcode id=1727 lang=cpp
 *
 * [1727] Largest Submatrix With Rearrangements
 */

// @lc code=start
class Solution {
  public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size(), ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c && i != 0; j++) {
                if (matrix[i][j] != 0) matrix[i][j] += matrix[i - 1][j];
            }

            vector<int> v = matrix[i];
            sort(v.begin(), v.end(), greater());
            for (int j = 0; j < c; j++) ans = max(ans, v[j] * (j + 1));
        }

        return ans;
    }
};
// @lc code=end
