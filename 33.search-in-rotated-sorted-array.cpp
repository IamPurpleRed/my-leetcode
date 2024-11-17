/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
  public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) return (nums[0] == target) ? 0 : -1;
        short l = 0, r = nums.size() - 1, m = 0;
        while (l <= r) {
            m = (l + r) >> 1;
            if (nums[m] == target) return m;
            else if (nums[l] <= nums[m]) {  // nums[l]~nums[m] 為順序排列
                if (nums[l] <= target && target <= nums[m]) r = m - 1;
                else l = m + 1;
            } else {
                if (nums[m] <= target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
        }

        return -1;
    }
};
// @lc code=end
