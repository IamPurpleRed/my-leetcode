/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
  public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sum(10000);
        for (int n : nums) sum[n] += n;
        nums[2] += nums[0];
        for (auto it = sum.begin() + 3; it != sum.end(); it++)
            *it += max(*(it - 2), *(it - 3));

        return max(*(sum.end() - 1), *(sum.end() - 2));
    }
};

// @lc code=end
