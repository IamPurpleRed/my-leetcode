/*
 * @lc app=leetcode id=2482 lang=cpp
 *
 * [2482] Difference Between Ones and Zeros in Row and Column
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> row0, row1, col0, col1;
        for (vector<int> r : grid) {
            int cnt0 = 0, cnt1 = 0;
            for (int i : r) {
                if (i) cnt1++;
                else cnt0++;
            }
            row0.push_back(cnt0);
            row1.push_back(cnt1);
        }

        for (int c = 0; c < grid[0].size(); c++) {
            int cnt0 = 0, cnt1 = 0;
            for (int i = 0; i < grid.size(); i++) {
                if (grid[i][c]) cnt1++;
                else cnt0++;
            }
            col0.push_back(cnt0);
            col1.push_back(cnt1);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < grid.size(); i++) {
            vector<int> v;
            for (int j = 0; j < grid[0].size(); j++) {
                v.push_back(row1[i] + col1[j] - row0[i] - col0[j]);
            }
            ans.push_back(v);
        }

        return ans;
    }
};
// @lc code=end
