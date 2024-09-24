/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0;
        for (int n : nums) {
            sum = max(sum + n, n);
            ans = max(ans, sum);
        }

        return ans;
    }
};
// @lc code=end
