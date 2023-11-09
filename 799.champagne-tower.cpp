/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
class Solution {
  public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double amount[100][100] = {0};
        amount[0][0] = poured;

        for (short r = 0; r <= query_row; r++) {
            for (short c = 0; c <= r; c++) {
                if (amount[r][c] > 1) {
                    double fill = amount[r][c] - 1;
                    amount[r][c] = 1;
                    if (r != query_row) {
                        amount[r + 1][c] += (fill / 2);
                        amount[r + 1][c + 1] += (fill / 2);
                    }
                }
            }
        }

        return amount[query_row][query_glass];
    }
};
// @lc code=end
