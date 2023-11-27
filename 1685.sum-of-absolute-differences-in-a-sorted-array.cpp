/*
 * @lc app=leetcode id=1685 lang=cpp
 *
 * [1685] Sum of Absolute Differences in a Sorted Array
 */

// @lc code=start
class Solution {
  public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int sum_left = 0, sum_right = 0, len = nums.size();
        for (int n : nums) sum_right += n;
        for (int i = 0; i < len; i++) {
            sum_left += nums[i];
            sum_right -= nums[i];
            ans.push_back(nums[i] * (2 * i - len + 2) - sum_left + sum_right);
            // (nums[i] * (i + 1) - sum_left) +
            // (sum_right - nums[i] * (len - i - 1))
        }

        return ans;
    }
};
// @lc code=end
