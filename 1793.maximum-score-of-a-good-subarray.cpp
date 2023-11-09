/*
 * @lc app=leetcode id=1793 lang=cpp
 *
 * [1793] Maximum Score of a Good Subarray
 */

// @lc code=start
class Solution {
  public:
    int maximumScore(vector<int>& nums, int k) {
        int l = k, r = k;
        int min = nums[k];
        int ans = nums[k];

        while ((l > 0) || (r < nums.size() - 1)) {
            if ((l == 0) ||
                (r < nums.size() - 1 && nums[r + 1] > nums[l - 1])) {
                r++;
                min = std::min(min, nums[r]);
            } else {
                l--;
                min = std::min(min, nums[l]);
            }
            ans = std::max(ans, min * (r - l + 1));
        }

        return ans;
    }
};
// @lc code=end
