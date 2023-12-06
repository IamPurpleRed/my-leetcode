/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 */

// @lc code=start
class Solution {
  public:
    int totalMoney(int n) {
        int w = n / 7, last = n % 7;
        return (28 + 21 + 7 * w) * w / 2 + (1 + w + last + w) * last / 2;
    }
};
// @lc code=end
