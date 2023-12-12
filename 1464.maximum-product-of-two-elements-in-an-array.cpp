/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 */

// @lc code=start
class Solution {
  public:
    int maxProduct(vector<int>& nums) {
        int b1 = 0, b2 = 0;
        for (int i : nums) {
            if (i > b1) b1 = i;
            else if (i == b1) b2 = i;
        }
        for (int i : nums) {
            b2 = (i == b1) ? b2 : max(i, b2);
        }

        return (b1 - 1) * (b2 - 1);
    }
};

// @lc code=end
