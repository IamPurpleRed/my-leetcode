/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
  public:
    int hammingWeight(uint32_t n) {
        short cnt = 0;
        while (n) {
            if (n & 1) cnt++;
            n /= 2;
        }

        return cnt;
    }
};
// @lc code=end
