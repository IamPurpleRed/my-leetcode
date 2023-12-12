/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int r = matrix[0].size(), c = matrix.size();
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                if (i == 0) {
                    vector<int> v;
                    v.push_back(matrix[i][j]);
                    ans.push_back(v);
                } else {
                    ans[j].push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};
// @lc code=end
