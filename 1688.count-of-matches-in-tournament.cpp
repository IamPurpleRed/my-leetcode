/*
 * @lc app=leetcode id=1688 lang=cpp
 *
 * [1688] Count of Matches in Tournament
 */

// @lc code=start
class Solution {
  public:
    int numberOfMatches(int n) {
        int ans = 0;
        while (n > 1) {
            if (n & 1) {
                n = n >> 1;
                ans += n;
                n++;
            } else {
                n = n >> 1;
                ans += n;
            }
        }

        return ans;
    }
};
// @lc code=end
