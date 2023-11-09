/*
 * @lc app=leetcode id=458 lang=cpp
 *
 * [458] Poor Pigs
 */

// @lc code=start
class Solution {
  public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log2(buckets) /
                    log2(int(minutesToTest / minutesToDie) + 1));
    }
};
// @lc code=end
